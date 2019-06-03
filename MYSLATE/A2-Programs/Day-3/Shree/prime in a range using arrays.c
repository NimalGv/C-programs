#include<stdio.h>
// 2: 57
#define SIZE 10
// NO OPTIMIZATION - >10.90
// removed all even numbers in num as well as factors ->4.1
// array ->2.015
int primes[SIZE];
int main()
{
int num, factor, till, primeCtr=1,  searchCtr;
primes[0]=2;
for(num = 3; num <= SIZE; num+=2){
    till =sqrt(num);

    for(searchCtr = 0; primes[searchCtr] <= till; searchCtr++)
        if(num % primes[searchCtr] == 0) break;

    if(primes[searchCtr] > till) primes[primeCtr++]=num;
}
printf("%d", primeCtr);
return 0;
 }

