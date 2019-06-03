#include<stdio.h>
// 2: 57
#define SIZE 10000000
// NO OPTIMIZATION - >10.90

int main()
{
int num, factor, till, primeCtr=1;
for(num = 3; num <= SIZE; num+=2)
{
till =sqrt(num);
for(factor = 3; factor <= till; factor+=2)
     if(num % factor ==0) break;
     if(factor > till) primeCtr++;
}
printf("%d", primeCtr);
return 0;
 }

