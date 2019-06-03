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

int num, raiseNum, searchNum, start, end, mid;

num = 13;
if(isPrime(num) == 1)
      {
          raiseNum = num * 1000000;

//          for(searchNum = 1; searchNum * searchNum < raiseNum; searchNum++);
       start = 1;
       end = 9999;
       mid = (start + end)/2;
       while(start < end)
       {
           if(mid * mid < raiseNum)
              start = mid + 1;
           else if(mid * mid > raiseNum )
               end = mid - 1;
           else break;
           mid = (start + end)/2;

       }
          printf("%.3f", (mid-1) / 1000.0);

      }
return 0;
}
