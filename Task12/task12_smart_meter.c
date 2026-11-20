#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct {int64_t normal_paise_per_kwh;int64_t peak_paise_per_kwh;} Tariff;
static int is_peak(int minute){return minute>=18*60&&minute<22*60;}
static int64_t charge(int64_t wh,int minute,const Tariff*t){int64_t rate=is_peak(minute)?t->peak_paise_per_kwh:t->normal_paise_per_kwh;return (wh*rate+500)/1000;}
int main(void){Tariff t;int64_t wh;int minute;FILE*f=fopen("tariff.cfg","r");if(!f){puts("Missing tariff.cfg (normal and peak paise/kWh)");return 1;}if(fscanf(f,"%lld %lld",(long long*)&t.normal_paise_per_kwh,(long long*)&t.peak_paise_per_kwh)!=2||t.normal_paise_per_kwh<0||t.peak_paise_per_kwh<0){fclose(f);puts("Invalid tariff config");return 1;}fclose(f);if(scanf("%lld %d",(long long*)&wh,&minute)!=2||wh<0||minute<0||minute>=1440){puts("Invalid Wh/minute input");return 1;}printf("Peak=%s Charge=%lld paise\n",is_peak(minute)?"yes":"no",(long long)charge(wh,minute,&t));return 0;}