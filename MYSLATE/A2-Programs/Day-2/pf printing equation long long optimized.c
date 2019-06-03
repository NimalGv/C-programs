#include<stdio.h>


int isPrime(long long num)
{
    long long factor, till;
    till = sqrt(num);
    for(factor = 3; factor <= till; factor+=2)
        if(num % factor ==0 ) return 0;
    return 1;
}
int main(){

long long int num = (2 * 1000000007LL), factor;
//num = 800;
for(factor=2;   num!=1     ; factor++)
{
      if(num % factor == 0)
      {

          while(num % factor == 0)
          {
              printf("%lld ", factor);
              num=num/ factor;
          }
          if(isPrime(num) == 1)
          {
              printf("%lld", num);
              break;
          }
      }


}

return 0;
}
