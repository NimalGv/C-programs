#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    /*
        sum of "n" odd numbers:
            3: 1+3+5=9;
            5: 1+3+5+7+9=25;
            10: 1+3+5+7+9+11+13+15+17+18=100;
            thus-> Sum of "n" odd numbers = (n*n)
    */
    printf("sum of odd: %d\n",n*n);
}
