#include<stdio.h>
#include<limits.h>

int main()
{

    int bricks = 15, nod=0, safe, power=1, ctr;
    long long  start, end, mid,  calcVal;

/*safe = bricks;
while(bricks)
{
nod++;
bricks/=10;
}
bricks = safe;
nod/=2;
for(ctr = 0;ctr < nod-1; ctr++)
 power = power * 10;
 start = power;
 end = power * 100;
 mid = (end + start) /2;*/
//printf("%d %d %d\n", start, end, mid);
start = 1;
end = 100;
mid = (end + start) /2;
 while(start < end)
 {
 calcVal = (mid * (mid+1))/2;
 if(calcVal < bricks)
      start = mid + 1;
else if(calcVal > bricks)
      end = mid - 1;
else break;
//printf("%d %d %d\n", start, end, mid);
mid = (end + start) /2;
 }
 printf("%lld", mid);
return 0;
}
