#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main(void){char line[128],*end;long prev,curr;if(!fgets(line,sizeof line,stdin)){puts("Input error");return 1;}errno=0;prev=strtol(line,&end,10);if(errno||end==line){puts("Invalid previous reading");return 1;}while(*end==' '||*end=='\t')end++;curr=strtol(end,&end,10);if(errno||curr<0||curr>65535||prev<0||prev>65535){puts("Invalid reading range");return 1;}printf("Readings accepted: %ld %ld\n",prev,curr);return 0;}