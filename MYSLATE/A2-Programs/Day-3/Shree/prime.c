#include<stdio.h>
// 2: 57


int main()
{


int num, factor, till;

num = 99999997;
till =sqrt(num);
for(factor = 2; factor <= till; factor++)
     if(num % factor ==0) break;

     if(factor > till) printf("Prime");
     else printf("Not Prime") ;
return 0;
 }

