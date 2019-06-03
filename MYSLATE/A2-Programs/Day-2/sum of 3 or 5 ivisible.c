#include<stdio.h>

#include<limits.h>

int main()
{

   int n, num;
   long long sum=0 ;
   n = INT_MAX;
   for(num = 3; num <= n; num++)
      if(num % 3 ==0  || num % 5  == 0)
             sum = sum + num;

             printf("%lld", sum);
return 0;
}
