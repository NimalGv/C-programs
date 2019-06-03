#include<stdio.h>
#define SIZE 10000000

int main()
{

int *primes = NULL, ctr, primeCtr=0,till, multiplier, prime, value;

primes = (int * )calloc(SIZE, sizeof(int));
primes[0] = primes[1] = 1;
till = sqrt(SIZE);
for(prime = 2; prime <= till; prime++)
{
   if(primes[prime]==1) continue;
   for(multiplier = 2,value = prime * multiplier;  value < SIZE;
                       multiplier++, value = prime * multiplier)
       primes[value]=1;
}
for(ctr = 0; ctr < SIZE; ctr++)
     if(primes[ctr] == 0) primeCtr++;
printf("%d", primeCtr);
return 0;
}
