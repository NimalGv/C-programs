#include<stdio.h>

int anyBaseAdder(int num1, int num2, int base)
{
     int dig1, dig2, resdig, carry=0, result=0, power=1;

     while(num1 || num2)
     {
     dig1 = num1 % 10;
     dig2 = num2 % 10;
     resdig = (dig1 + dig2 + carry) % base;
     carry = (dig1 + dig2 + carry) / base;
     num1/=10;
     num2/=10;
     result = resdig * power + result;
     power *=10;
     }
     if(carry ==1)
     {
         result = carry * power + result;
     }





return result;
}


int main()
{

int n1, n2, base = 2, res;
n1 = 1001;
n2 = 110011;
base = 2;

res = anyBaseAdder(n1, n2, base);
printf("%d + %d = %d in Base %d\n", n1 , n2, res, base);

n1 = 13764;
n2 = 2177;
base = 8;

res = anyBaseAdder(n1, n2, base);
printf("%d + %d = %d in Base %d\n", n1 , n2, res, base);

n1 = 123;
n2 = 13;
base = 4;

res = anyBaseAdder(n1, n2, base);
printf("%d + %d = %d in Base %d\n", n1 , n2, res, base);

n1 = 1011;
n2 = 11001;
base = 2;

res = anyBaseAdder(n1, n2, base);
printf("%d + %d = %d in Base %d\n", n1 , n2, res, base);


}
