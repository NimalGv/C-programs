#include<stdio.h>
#include<limits.h>

int main()
{
int n, no3, no5,no15;
long long sum3, sum5, sum15, sum;
n = INT_MAX;
no3 = n/ 3;
no5 = n/ 5;
no15 = n/ 15;
sum3 =  3LL * ( ( (no3)*(no3+1LL))/2 );
sum5 = 5LL*  (( (no5) *(no5+1LL))/2 );
sum15 =  15LL *  (( (no15)*(no15+1LL))/2 );
sum = sum3 + sum5 - sum15;
printf("%lld",sum);
return 0;
}
