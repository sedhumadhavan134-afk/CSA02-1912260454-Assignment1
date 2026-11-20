#include <stdio.h>
#include <limits.h>
#include <float.h>
typedef unsigned short meter_t;
unsigned int consumption(meter_t previous,meter_t current){return (unsigned int)(meter_t)(current-previous);}
int main(void){printf("sizeof(meter_t) = %zu bytes, maximum reading = %u\n",sizeof(meter_t),(unsigned)USHRT_MAX);printf("Consumption: %u units\n",consumption(1200,1530));printf("Consumption: %u units\n",consumption(65400,120));printf("sizeof int=%zu long=%zu long long=%zu float=%zu double=%zu\n",sizeof(int),sizeof(long),sizeof(long long),sizeof(float),sizeof(double));printf("INT_MAX=%d LONG_MAX=%ld LLONG_MAX=%lld FLT_DIG=%d DBL_DIG=%d\n",INT_MAX,LONG_MAX,LLONG_MAX,FLT_DIG,DBL_DIG);return 0;}