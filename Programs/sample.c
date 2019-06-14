#include<stdio.h>

int main(){
    char s[]="SmoomWISS";
    int end=9;
    for(int i=0; i<10; i++){
        printf("1%d %d\n", end, i);
        if(end==0){
            printf("%c", s[i]);
            break;
        }
        if(s[i]!=s[end] || i==end){
            end--;
            i--;
            printf("2%d %d\n", end, i);
        }else{
            end=9;
        }
    }
}
