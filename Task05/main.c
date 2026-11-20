#include <stdio.h>
#include "billing.h"
#ifdef DEBUG
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG_PRINT(...) ((void)0)
#endif
int main(void) {
    unsigned short previous = 1200, current = 1350;
    unsigned int units = consumption(previous, current);
    long total = compute_bill((int)units);
    if (total < 0) { puts("Invalid units"); return 1; }
    DEBUG_PRINT("previous=%hu current=%hu units=%u paise=%ld\n", previous, current, units, total);
    printf("Units=%u Bill=Rs %ld.%02ld\n", units, total / 100, total % 100);
    return 0;
}