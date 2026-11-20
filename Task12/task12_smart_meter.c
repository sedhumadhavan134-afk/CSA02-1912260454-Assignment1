#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>

typedef struct { int64_t normal_rate, peak_rate; } Tariff;
static int peak_at(int minute) { return minute >= 1080 && minute < 1320; }
static int add_checked(int64_t *sum, int64_t value) {
    if (value < 0 || *sum > INT64_MAX - value) return 0;
    *sum += value; return 1;
}
static int charge_wh(int64_t wh, int peak, const Tariff *t, int64_t *out) {
    int64_t rate = peak ? t->peak_rate : t->normal_rate;
    if (wh < 0 || rate < 0 || (rate && wh > (INT64_MAX - 500) / rate)) return 0;
    *out = (wh * rate + 500) / 1000; /* nearest paise, half up */
    return 1;
}
/* Split one 15-minute interval at 18:00 and 22:00.
   Energy is allocated uniformly by minute; remainder Wh goes to earliest minutes. */
static int interval_charge(int64_t wh, int start, int duration, const Tariff *t, int64_t *out) {
    if (wh < 0 || start < 0 || start >= 1440 || duration <= 0 || duration > 60) return 0;
    int64_t q = wh / duration, rem = wh % duration, total = 0;
    int offset = 0;
    while (offset < duration) {
        int minute = (start + offset) % 1440;
        int band = peak_at(minute);
        int run = 1;
        while (offset + run < duration &&
               peak_at((start + offset + run) % 1440) == band) ++run;
        int64_t segment_wh = q * run;
        int rem_in_segment = rem < run ? (int)rem : run;
        segment_wh += rem_in_segment;
        rem -= rem_in_segment;
        int64_t part;
        if (!charge_wh(segment_wh, band, t, &part) || !add_checked(&total, part)) return 0;
        offset += run;
    }
    *out = total; return 1;
}
int main(void) {
    Tariff t; long long normal, peak, wh; int start, duration;
    int64_t annual_paise = 0; unsigned long intervals = 0;
    FILE *cfg = fopen("tariff.cfg", "r");
    if (!cfg) { puts("Missing tariff.cfg"); return 1; }
    if (fscanf(cfg, "%lld %lld", &normal, &peak) != 2 || normal < 0 || peak < 0) {
        fclose(cfg); puts("Invalid tariff.cfg"); return 1;
    }
    fclose(cfg); t.normal_rate = normal; t.peak_rate = peak;
    puts("Enter interval records: Wh start_minute duration_minute (Ctrl+D to finish)");
    while (scanf("%lld %d %d", &wh, &start, &duration) == 3) {
        int64_t amount;
        if (!interval_charge(wh, start, duration, &t, &amount) ||
            !add_checked(&annual_paise, amount)) {
            puts("Invalid interval or arithmetic overflow"); return 1;
        }
        ++intervals;
        printf("Interval %lu: %lld paise\n", intervals, (long long)amount);
    }
    if (!feof(stdin)) { puts("Invalid input record"); return 1; }
    printf("Intervals processed: %lu\nYear-to-date total: %lld paise (Rs %lld.%02lld)\n",
           intervals, (long long)annual_paise,
           (long long)(annual_paise / 100), (long long)(annual_paise % 100));
    return 0;
}