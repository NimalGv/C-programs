#include<stdio.h>

int main(){
    int a[]={1, 2, 3, 4, 77, 97, 5, 6, 7, 8, 9, 10};
    int max1=0, max2=0;
    int size;
    size=sizeof(a)/sizeof(int);
    for(int i=0;i<size;i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }else if(a[i]>max2){
            max2=a[i];
        }
    }
    printf("\n%d", max2);
}
