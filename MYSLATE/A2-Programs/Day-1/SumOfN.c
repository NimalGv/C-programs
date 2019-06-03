#include<stdio.h>
int main(){
    int range,sum_of_odd,sum_of_even,no_odd,no_even,sum=0;
    scanf("%d",&range);
    no_even=range/2;
    no_odd=range-no_even;
    sum_of_even=no_even*(no_even+1);
    sum_of_odd=no_odd*no_odd;
    printf("Sum of N: %d",sum_of_even+sum_of_odd);
    /*
        sum of "n":
            sum of odd        +        sum of even;

        n=range-no_of_even               n=range/2

               n*n            +           n*(n+1)

               thus -> sum of "n" numbers

    */
}
