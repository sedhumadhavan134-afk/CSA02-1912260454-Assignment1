#include <stdio.h>
#include <limits.h>
int main(void) {
    const long long bill_paise[] = {5000, 5000, 16250, 27500, 95000};
    const int counts[] = {4000, 60000, 800000};
    for (size_t k = 0; k < sizeof counts / sizeof counts[0]; ++k) {
        long long exact_paise = 0;
        double float_rupees = 0.0;
        for (int i = 0; i < counts[k]; ++i) {
            long long p = bill_paise[i % 5];
            exact_paise += p;
            float_rupees += (float)p / 100.0f;
        }
        printf("%d bills: integer=%lld paise (Rs %lld.%02lld), float=%.2f rupees, difference=%.6f\n",
               counts[k], exact_paise, exact_paise / 100, exact_paise % 100,
               float_rupees, float_rupees - (double)exact_paise / 100.0);
    }
    printf("INT_MAX=%d LLONG_MAX=%lld\n", INT_MAX, LLONG_MAX);
    return 0;
}