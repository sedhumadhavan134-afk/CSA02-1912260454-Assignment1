#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

typedef unsigned short meter_t;
#define MODULUS 65536U
#define SLAB1 100U
#define SLAB2 200U
#define RATE2 225LL
#define RATE3 450LL
#define FIXED 5000LL

static int read_token(const char *prompt, char *buf, size_t size) {
    printf("%s", prompt);
    if (!fgets(buf, (int)size, stdin)) return 0;
    buf[strcspn(buf, "\n")] = '\0';
    return 1;
}
static int parse_reading(const char *s, meter_t *out) {
    char *end; long v;
    errno = 0; v = strtol(s, &end, 10);
    while (*end == ' ' || *end == '\t' || *end == '\r') ++end;
    if (errno || end == s || *end != '\0' || v < 0 || v > 65535) return 0;
    *out = (meter_t)v; return 1;
}
static unsigned int units_used(meter_t previous, meter_t current) {
    return (unsigned int)(meter_t)(current - previous);
}
static long long bill_paise(unsigned int units) {
    long long energy = 0;
    if (units > SLAB2) energy += (long long)(units - SLAB2) * RATE3;
    if (units > SLAB1) {
        unsigned int middle = units < SLAB2 ? units - SLAB1 : SLAB2 - SLAB1;
        energy += (long long)middle * RATE2;
    }
    return FIXED + energy;
}
int main(void) {
    char household[64], previous_text[64], current_text[64];
    meter_t previous, current;
    if (!read_token("Household ID: ", household, sizeof household) || household[0] == '\0' ||
        !read_token("Previous meter reading (0-65535): ", previous_text, sizeof previous_text) ||
        !read_token("Current meter reading (0-65535): ", current_text, sizeof current_text) ||
        !parse_reading(previous_text, &previous) || !parse_reading(current_text, &current)) {
        fprintf(stderr, "Invalid input. Check household ID and meter readings.\n");
        return 1;
    }
    unsigned int units = units_used(previous, current);
    long long total = bill_paise(units);
    printf("\nHousehold: %s\nUnits consumed: %u\nEnergy + fixed bill: Rs %lld.%02lld\n",
           household, units, total / 100, total % 100);
    return 0;
}