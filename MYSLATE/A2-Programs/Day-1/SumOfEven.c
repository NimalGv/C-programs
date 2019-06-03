#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    /*
        sum of "n" even numbers is:
            3: 2+4+6=12;
            5: 2+4+6+8+10=30;
            10: 2+4+6+8+10+12+14+16+18+20=110;
            thus-> sum of "n" even numbers=n*(n+1)
    */
    printf("Sum of Even:%d\n",num*(num+1));
}
