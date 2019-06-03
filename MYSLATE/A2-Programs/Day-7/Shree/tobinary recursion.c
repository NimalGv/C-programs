#include<stdio.h>

int toBinary(int value)
{

   if(value < 2) return value;
    return toBinary(value/2) * 10 + (value%2);
}
int toOctal(int value)
{

   if(value <8) return value;
   return toOctal(value/8) * 10 + (value%8);
}

int main()
{
   printf("%d %d", toBinary(525), toOctal(1234));
return 0;
}
