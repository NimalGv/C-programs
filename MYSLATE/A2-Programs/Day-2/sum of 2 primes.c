#include<stdio.h>
int isPrime(int num)
{
int til, factor;
til = sqrt(num);
for(factor = 2; factor <= til; factor++)
if(num % factor == 0) return 0;
return 1;
}
int main()
{

int num;
scanf("%d", &num);
if(num > 2 && num % 2 == 0)
     printf("Yes");
     else if(isPrime(num-2) == 1)
          printf("Yes");
          else printf("No");
return ;
}
