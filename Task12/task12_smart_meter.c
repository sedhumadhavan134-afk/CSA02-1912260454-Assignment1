#include <stdio.h>
#include <stdint.h>
#include <limits.h>
typedef struct { int64_t normal_paise_per_kwh, peak_paise_per_kwh; } Tariff;
static int is_peak(int minute) { return minute >= 18*60 && minute < 22*60; }
static int charge(int64_t wh, int minute, const Tariff *t, int64_t *out) {
    int64_t rate = is_peak(minute) ? t->peak_paise_per_kwh : t->normal_paise_per_kwh;
    if (rate < 0 || (rate != 0 && wh > (INT64_MAX - 500) / rate)) return 0;
    *out = (wh * rate + 500) / 1000; /* nearest paise, half up */
    return 1;
}
int main(void) {
    Tariff t; long long normal_rate, peak_rate, input_wh; int minute; int64_t result;
    FILE *f = fopen("tariff.cfg", "r");
    if (!f) { puts("Missing tariff.cfg"); return 1; }
    if (fscanf(f, "%lld %lld", &normal_rate, &peak_rate) != 2 ||
        normal_rate < 0 || peak_rate < 0) {
        fclose(f); puts("Invalid tariff config"); return 1;
    }
    fclose(f);
    t.normal_paise_per_kwh = normal_rate; t.peak_paise_per_kwh = peak_rate;
    if (scanf("%lld %d", &input_wh, &minute) != 2 ||
        input_wh < 0 || minute < 0 || minute >= 1440) {
        puts("Invalid Wh/minute input"); return 1;
    }
    if (!charge(input_wh, minute, &t, &result)) {
        puts("Charge overflow"); return 1;
    }
    printf("Peak=%s Charge=%lld paise\n",
           is_peak(minute) ? "yes" : "no", (long long)result);
    return 0;
}
