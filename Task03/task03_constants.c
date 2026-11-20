#include <stdio.h>
#define SLAB1_UNITS 100
#define SLAB2_UNITS 200
#define RATE1_PAISE 0L
#define RATE2_PAISE 225L
#define RATE3_PAISE 450L
#define FIXED_CHARGE_PAISE 5000L
long compute_bill(int units){long p=FIXED_CHARGE_PAISE;if(units>SLAB2_UNITS)p+=(long)(units-SLAB2_UNITS)*RATE3_PAISE;if(units>SLAB1_UNITS){int u=units<SLAB2_UNITS?units-SLAB1_UNITS:SLAB2_UNITS-SLAB1_UNITS;p+=(long)u*RATE2_PAISE;}if(units>0&&units<=SLAB1_UNITS)p+=(long)units*RATE1_PAISE;return p;}
int main(void){int a[]={0,100,150,200,350};for(int i=0;i<5;i++){long p=compute_bill(a[i]);printf("%3d units -> Rs %ld.%02ld\n",a[i],p/100,p%100);}return 0;}