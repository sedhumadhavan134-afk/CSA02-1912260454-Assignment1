#include <stdio.h>
#include <limits.h>
#include <stdint.h>
int main(void) {
    printf("sizeof(unsigned short)=%zu; USHRT_MAX=%u\n", sizeof(unsigned short), USHRT_MAX);
    printf("sizeof(unsigned int)=%zu; UINT_MAX=%u\n", sizeof(unsigned int), UINT_MAX);
    printf("sizeof(long long)=%zu; LLONG_MAX=%lld\n", sizeof(long long), LLONG_MAX);
    printf("sizeof(int64_t)=%zu bytes\n", sizeof(int64_t));
    printf("Recommended: 16-bit unsigned meter register, validated unsigned units, string IDs, integer-paise currency, checked 64-bit totals.\n");
    printf("Tariffs: compile-time constants for fixed rates; validated configuration for frequently revised rates.\n");
    return 0;
}