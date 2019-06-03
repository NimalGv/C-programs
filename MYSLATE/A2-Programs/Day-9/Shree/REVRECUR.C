#include<stdio.h>


long int revnum(long int num)
{
     long int digit, compute, retval;
     static int power = 1;
     if(num == 0)
     return num;
     digit = num % 10;
    retval =  revnum(num / 10) ;
    compute = digit * power + retval;
    power = power * 10;
    //printf("%d \n", power);
    return compute;

}


int main()
{


printf("%ld", revnum(12345L));
return 0;
}
