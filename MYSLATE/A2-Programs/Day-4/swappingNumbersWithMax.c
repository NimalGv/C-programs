#include<stdio.h>

int main(){
    int a[]={12, 46, 0, 35, 7900, 553, 4357, 55, 2, 7875, 3, 86, 342, 6, 2425};
    int size, max;
    size=sizeof(a)/sizeof(int);
    max=a[size-1];
    for(int index=size-2;index>=0;index--){
        if(a[index]<max)
            a[index]=max;
        else
            max=a[index];
    }
    for(int i=0;i<size;printf("%d ",a[i++]));

}

