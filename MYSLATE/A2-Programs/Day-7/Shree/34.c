#include<stdio.h>

int threeFour(int term)
{

 if(term == 1) return 3;
 if(term == 2) return 4;
 if(term % 2 == 0)
      return threeFour ((term/2) - 1)  * 10 + 4;
      else
      return threeFour(term/2) * 10 + 3;

}


int main()
{
    int num;
    for(num = 1; num < 1000; num++)
  printf("%d ", threeFour(num));
return 0;
}
