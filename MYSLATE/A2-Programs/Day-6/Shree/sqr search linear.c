#include<stdio.h>

isPrime(int num)
{
   int factor, till;
   till = sqrt(num);
   for(factor = 2; factor <= till ; factor++)
       if(num % factor == 0) return 0;

       return 1;
}

int main()
{

int num, raiseNum, searchNum;

num = 97;
if(isPrime(num) == 1)
      {
          raiseNum = num * 1000000;

          for(searchNum = 1; searchNum * searchNum < raiseNum; searchNum++);
          printf("%.3f", (searchNum-1) / 1000.0);

      }
return 0;
}
