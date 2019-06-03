// 2: 19 2:37
//1111111111
#include<stdio.h>
//#define DEBUG
int panDigital(long long num)
{
long long consValue=0, power=1;
int ctr, digit;
while(num)
{
digit = num % 10;
for(ctr =0, power =1; ctr < digit; ctr++)
   //  power = power * 10;
   power = power * 2;

    // consValue += (digit*power);
    consValue+=power;
     num = num / 10;
}

//if(consValue == 9876543210LL) return 1;
#ifdef DEBUG
printf("%lld ", consValue);
#endif
if(consValue == 1023) return 1;
return 0;
}
int main()
{
     int abc, def, ghij;
     long long abcdefghij;

    for(abc = 100; abc < 1000; abc++)
     {

        for(def = 100; def < 1000; def++)
        {
             ghij = abc + def;
             abcdefghij = (abc * 1000 + def ) * 10000LL + ghij;
             if(ghij > 999 && panDigital(abcdefghij) == 1)
             printf("%d + %d = %d\n", abc, def, ghij);
        }
     }
#ifdef DEBUG
printf("%d", panDigital(4578091236));
#endif // DEBUG

return 0;
}
