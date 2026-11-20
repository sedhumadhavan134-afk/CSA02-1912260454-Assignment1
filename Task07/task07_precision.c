#include <stdio.h>
int main(void) {
    printf("5/2 = %d (integer division)\n", 5 / 2);
    printf("(double)5/2 = %.2f\n", (double)5 / 2);
    printf("(int)3.9 = %d (truncates toward zero)\n", (int)3.9);
    float rupees = 0.0f;
    long long paise = 0;
    for (int i = 0; i < 4000; ++i) {
        rupees += 0.1f; /* 10 paise expressed approximately as 0.1 rupee */
        paise += 10;    /* exact 10 paise */
    }
    printf("Float accumulation = %.6f rupees\n", rupees);
    printf("Integer-paise total = %lld paise = Rs %lld.%02lld\n",
           paise, paise / 100, paise % 100);
    printf("Difference from exact total = %.6f rupees\n", rupees - (double)paise / 100.0);
    return 0;
}