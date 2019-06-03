#include<stdio.h>

int main(){

int num = 800, factor;

for(factor=2;   num!=1     ; factor++)
{
      if(num % factor == 0)
      {

          while(num % factor == 0)
          {
              printf("%d ", factor);
              num=num/ factor;
          }

      }


}

return 0;
}
