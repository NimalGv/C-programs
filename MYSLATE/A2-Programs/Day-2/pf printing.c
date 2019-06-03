#include<stdio.h>

int main(){

int num = 9800, factor;

for(factor=2;   num!=1     ; factor++)
{
      if(num % factor == 0)
      {
          printf("%d ", factor);
          while(num % factor == 0)
         num=num/ factor;
      }


}

return 0;
}
