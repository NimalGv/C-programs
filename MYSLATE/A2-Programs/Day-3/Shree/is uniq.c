#include<stdio.h>


int isUniq(int num)
{
    int digit, mask, res =0;
    while(num)
    {
    digit = num % 10;
    mask = 1 << digit;
    if((res&mask) ==mask) return 0;
    res = res | mask;
    num = num / 10;
    }
   return 1;

}




int main()
{

printf("%d\n", isUniq(1234));
printf("%d\n", isUniq(5667));
printf("%d\n", isUniq(55521));
printf("%d\n", isUniq(804567));
printf("%d\n", isUniq(1098760));
printf("%d\n", isUniq(1234567));

return 0;
}
