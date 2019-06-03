// You are using GCC
#include<stdio.h>

int main(){
    int number, one=0, two=0, no=0;
    scanf("%d", &number);
    while(number){
        if(number&1){
            printf("1: %d\n", number&1);
            if(one==0){
                one=1;
                two=0;
            }else{
                no=1;
                break;
            }
        }else{
            printf("0: %d\n", number&1);
            if(two==0){
                two=1;
                one=0;
            }else{
                no=1;
                break;
            }
        }
        number=number>>1;
    }
    if(no)
        printf("Yes");
    else
        printf("No");
}
