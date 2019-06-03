#include<stdio.h>

int gcd(int n1, int n2)
{
    int factor;
     if(n1 > n2)
     {
        n1 = n1 + n2;
        n2  = n1 - n2;
        n1 = n1 - n2;
     }
     if(n2 % n1 ==0 ) return n1;

     for(factor = n1/2; factor >= 1; factor--)
        if(n1 % factor == 0 && n2 % factor == 0) return factor;

}



int main()
{
int n, num, result=1;

n = 20;
for(num = 1; num <= n; num++)
   result = result * (num/gcd(result,num));

   printf("%d", result);

return 0;
}
