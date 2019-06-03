#include<stdio.h>


int main()
{
   int num, power, pb =0, safe, digit, len=0;
   scanf("%d", &num);
    safe = num;
    while(num)
    {
        num/=10;
        len++;
    }
    num= safe;
   do
   {
   power = 1;
   pb = 0;
      safe = num;
   while(num)
   {
   digit = num % 10;
   if(digit > 0)
        pb = power + pb;
        power = power * 10;
        num = num / 10;
        }
        printf("%0*d\n",len, pb);
        num =  safe;
        num = num - pb;
        }while(num);
return 0;
}
