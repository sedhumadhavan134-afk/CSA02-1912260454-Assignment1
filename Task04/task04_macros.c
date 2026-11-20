#include <stdio.h>
#define RUPEES_TO_PAISE(r) ((long)(r)*100L)
#define SQUARE(x) ((x)*(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
static inline int square_fn(int x){return x*x;}
static inline int max_fn(int a,int b){return a>b?a:b;}
int main(void){int a=3,b=7;printf("Square macro: %d\n",SQUARE(a+1));printf("Square inline: %d\n",square_fn(a+1));printf("Max macro: %d, inline: %d\n",MAX(a,b),max_fn(a,b));printf("Rs 12 -> %ld paise\n",RUPEES_TO_PAISE(12));return 0;}