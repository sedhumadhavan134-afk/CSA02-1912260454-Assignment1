#include "billing.h"
unsigned int consumption(unsigned short previous, unsigned short current) {
    return (unsigned int)(unsigned short)(current - previous);
}
long compute_bill(int units) {
    if (units < 0) return -1L;
    long total = FIXED_CHARGE_PAISE;
    if (units > SLAB2_UNITS) total += (long)(units - SLAB2_UNITS) * RATE3_PAISE;
    if (units > SLAB1_UNITS) {
        int middle = units < SLAB2_UNITS ? units - SLAB1_UNITS : SLAB2_UNITS - SLAB1_UNITS;
        total += (long)middle * RATE2_PAISE;
    }
    return total;
}