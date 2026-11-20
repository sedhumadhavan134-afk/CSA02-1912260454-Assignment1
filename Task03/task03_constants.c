#include <stdio.h>
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0LL
#define RATE2_PAISE 225LL
#define RATE3_PAISE 450LL
#define FIXED_CHARGE_PAISE 5000LL
static int compute_bill(int units, long long *out) {
    if (units < 0 || out == NULL) return 0;
    long long energy = 0;
    if (units > SLAB2_UNITS) energy += (long long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        int middle = units < SLAB2_UNITS ? units - SLAB1_UNITS : SLAB2_UNITS - SLAB1_UNITS;
        energy += (long long)middle * RATE2_PAISE;
    } else energy += (long long)units * RATE1_PAISE;
    *out = FIXED_CHARGE_PAISE + energy;
    return 1;
}
int main(void) {
    const int tests[] = {0, 100, 150, 200, 350};
    for (size_t i = 0; i < sizeof tests / sizeof tests[0]; ++i) {
        long long p;
        if (compute_bill(tests[i], &p))
            printf("%3d units -> Rs %lld.%02lld\n", tests[i], p / 100, p % 100);
    }
    long long ignored;
    printf("Negative input rejected: %s\n", compute_bill(-1, &ignored) ? "no" : "yes");
    return 0;
}