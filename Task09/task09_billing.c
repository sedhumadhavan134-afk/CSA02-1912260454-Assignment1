#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
typedef unsigned short meter_t;
#define SLAB1 100
#define SLAB2 200
#define RATE2 225LL
#define RATE3 450LL
#define FIXED 5000LL
unsigned int used(meter_t p,meter_t c){return (unsigned int)(meter_t)(c-p);}
long long bill(unsigned int u){long long e=0;if(u>SLAB2)e+=(long long)(u-SLAB2)*RATE3;if(u>SLAB1)e+=(long long)(u<SLAB2?u-SLAB1:SLAB2-SLAB1)*RATE2;return FIXED+e;}
int main(void){unsigned short p,c;if(scanf("%hu %hu",&p,&c)!=2){puts("Invalid input");return 1;}unsigned int u=used(p,c);long long b=bill(u);printf("Units consumed: %u\nBill: Rs %lld.%02lld\n",u,b/100,b%100);return 0;}