#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int testcase, size, *array;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        array=(int *)malloc(size*sizeof(int));
        for(int i=0; i<size; i++)
            scanf("%d", &array[i]);
        for(int i=size-1; i>=0; printf("%d ", array[i--]));
        printf("\n");
    }
 /* int a[]={1,2,3,4,5,6,7,8};
    int len=8;
    int mid=len/2;
    for(int i=0; i<=mid; i++)
        swap(&a[i], &a[len-1-i]);
    for(int i=0; i<len; printf("%d ", a[i++]));*/
    return 0;
}
