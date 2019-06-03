#include<stdio.h>

int main(){

long long int num = 1000000007LL, factor;

for(factor=2;   num!=1     ; factor++)
{
      if(num % factor == 0)
      {

          while(num % factor == 0)
          {
              printf("%lld ", factor);
              num=num/ factor;
          }

      }


}

return 0;
}
