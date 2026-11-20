#include <stdio.h>
#include <limits.h>
#include <float.h>
typedef unsigned short meter_t;
_Static_assert(USHRT_MAX == 65535, "This program requires a 16-bit unsigned short meter register");
unsigned int consumption(meter_t previous, meter_t current) {
    return (unsigned int)(meter_t)(current - previous);
}
int main(void) {
    printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n", sizeof(meter_t), (unsigned)USHRT_MAX);
    printf("Consumption: %u units\n", consumption(1200, 1530));
    printf("Consumption: %u units\n", consumption(65400, 120));
    printf("sizeof char=%zu short=%zu int=%zu long=%zu long long=%zu float=%zu double=%zu\n",
           sizeof(char), sizeof(short), sizeof(int), sizeof(long), sizeof(long long), sizeof(float), sizeof(double));
    printf("SHRT_MAX=%d USHRT_MAX=%u INT_MAX=%d LONG_MAX=%ld LLONG_MAX=%lld FLT_DIG=%d DBL_DIG=%d\n",
           SHRT_MAX, USHRT_MAX, INT_MAX, LONG_MAX, LLONG_MAX, FLT_DIG, DBL_DIG);
    return 0;
}