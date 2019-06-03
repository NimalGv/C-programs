#include<stdio.h>
#include<malloc.h>

int main(){
    int array[]={11, 2, 3, 4, 77, 95, 5, 6, 7, 8, 9, 10}              ;
    int size, minpos, temp;

    size=sizeof(array)/sizeof(int);
    for(int i=0;i<size-1;i++){
        minpos=i;
        for(int j=i+1;j<size;j++){
            if(array[j]<array[minpos]){
                minpos=j;
            }
        }
            temp=array[minpos];
            array[minpos]=array[i];
            array[i]=temp;

    }
    for(int i=0;i<size;printf("%d ", array[i++]));
}
