#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <limits.h>
typedef unsigned short meter_t;
_Static_assert(USHRT_MAX == 65535, "Requires 16-bit unsigned short");
#define SLAB1 100U
#define SLAB2 200U
#define RATE2 225LL
#define RATE3 450LL
#define FIXED 5000LL
static int parse_readings(char *line, meter_t *previous, meter_t *current) {
    char *p = line, *end; errno = 0;
    long a = strtol(p, &end, 10);
    if (p == end || errno || a < 0 || a > 65535) return 0;
    p = end; while (isspace((unsigned char)*p)) ++p;
    errno = 0; long b = strtol(p, &end, 10);
    if (p == end || errno || b < 0 || b > 65535) return 0;
    p = end; while (isspace((unsigned char)*p)) ++p;
    if (*p != '\0') return 0;
    *previous = (meter_t)a; *current = (meter_t)b; return 1;
}
static unsigned int used(meter_t p, meter_t c) { return (unsigned int)(meter_t)(c - p); }
static long long bill(unsigned int u) {
    long long energy = 0;
    if (u > SLAB2) energy += (long long)(u - SLAB2) * RATE3;
    if (u > SLAB1) energy += (long long)(u < SLAB2 ? u - SLAB1 : SLAB2 - SLAB1) * RATE2;
    return FIXED + energy;
}
int main(void) {
    char line[128]; meter_t p, c;
    puts("Enter previous and current readings (0..65535):");
    if (!fgets(line, sizeof line, stdin) || !parse_readings(line, &p, &c)) {
        puts("Invalid input: enter exactly two readings in range.");
        return 1;
    }
    unsigned int units = used(p, c); long long total = bill(units);
    printf("Units consumed: %u\nBill: Rs %lld.%02lld\n", units, total / 100, total % 100);
    return 0;
}