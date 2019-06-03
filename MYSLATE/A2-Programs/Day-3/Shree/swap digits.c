#include<stdio.h>

long long int digitSwapper(long long num, int p1, int p2)
{
    int nod =0, ctr, dig1, dig2;
    long long safe , pow1, pow2;
    safe =  num;

    while(num)
    {
        num/=10;
        nod++;
    }
    num = safe;
    p1 = nod - p1 + 1;
    p2 = nod - p2 + 1;
    for(ctr = 1, pow1=1; ctr < p1; ctr++)
         pow1 = pow1 * 10;
    for(ctr = 1, pow2=1; ctr < p2; ctr++)
         pow2 = pow2 * 10;
    dig1 = (num / pow1) % 10;
    dig2 = (num / pow2) % 10;
    num = num - dig1 * pow1;
num = num - dig2 * pow2;
num = num + dig2 * pow1;
num = num + dig1 * pow2;
return num;
}



int main()
{
    printf("%lld\n",digitSwapper(8361209,2,7));
    printf("%lld\n",digitSwapper(12345678,2,4));
    printf("%lld\n",digitSwapper(90451235,3,8));
    printf("%lld\n",digitSwapper(6974,1,2));
 printf("%lld\n",digitSwapper(6974,3,4));
    return 0;
}
