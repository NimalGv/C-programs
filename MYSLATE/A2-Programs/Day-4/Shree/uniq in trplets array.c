#include<stdio.h>

int dectoNbase(int num, int base)
{
     int res=0, power=1, digit;

     while(num)
     {
     digit = num % base;
     res = digit * power + res;
     power*=10;
     num = num / base;
     }
return res;
}
// 2220
int Nbasetodec(int num, int base)
{
     int res=0, power=1, digit;

     while(num)
     {
     digit = num % 10;
     res = digit * power + res;
     power*=base;
     num = num / 10;
     }
return res;
}

int XORNbase(int inp1, int inp2 , int base)
{
    int dig1, dig2, resdig, res=0, power=1;
    while(inp1 || inp2)
  {
    dig1 = inp1 % 10;
    dig2 =inp2 % 10;
    resdig  = (dig1 + dig2) % base;
    res = resdig * power + res;
    power*=10;
    inp1 /= 10;
    inp2 /=10;
}
    return res;
}

int main()
{

  int arr[] = {123,113,145,134,134,113,92,113,123,123,145,145, 134};
  int size, index, uniq=0;

  size= sizeof(arr) / sizeof(int);

  for(index = 0; index < size; index++)
      uniq = XORNbase(uniq, dectoNbase(arr[index],3),3);

  printf("%d", Nbasetodec(uniq, 3));
return 0;
}
