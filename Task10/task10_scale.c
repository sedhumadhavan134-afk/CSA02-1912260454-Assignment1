#include <stdio.h>
#include <limits.h>
int main(void){long long paise_per_bill=95000LL;int n[]={4000,60000,800000};for(int i=0;i<3;i++){long long exact=paise_per_bill*n[i];double approx=(double)paise_per_bill/100.0*n[i];printf("%d bills: exact=%lld paise, double=%.2f rupees\n",n[i],exact,approx);}printf("INT_MAX=%d LLONG_MAX=%lld\n",INT_MAX,LLONG_MAX);return 0;}