#include <stdio.h>
#include "billing.h"
unsigned int consumption(unsigned short p,unsigned short c){return (unsigned int)(unsigned short)(c-p);}
long compute_bill(int u){long p=FIXED_CHARGE_PAISE;if(u>200)p+=(long)(u-200)*RATE3_PAISE;if(u>100)p+=(long)(u<200?u-100:100)*RATE2_PAISE;return p;}
#ifdef DEBUG
#define DEBUG_PRINT(...) fprintf(stderr,__VA_ARGS__)
#else
#define DEBUG_PRINT(...) ((void)0)
#endif
int main(void){int units=(int)consumption(1200,1350);long bill=compute_bill(units);DEBUG_PRINT("debug units=%d bill_paise=%ld\n",units,bill);printf("Units=%d Bill=Rs %ld.%02ld\n",units,bill/100,bill%100);return 0;}