#include<stdio.h>
#include<stdlib.h>

int main(){
    int testcase, temp, d, size, *array;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        scanf("%d", &d);
        array=(int *)malloc(size*sizeof(int));
        for(int i=0; i<size; i++)
            scanf("%d", &array[i]);
        while(d--){
            temp=array[0];
            for(int i=0; i<size-1; i++)
                array[i]=array[i+1];
            array[size-1]=temp;
        }
        for(int i=0; i<size; printf("%d ", array[i++]));
        printf("\n");
    }
    return 0;
}
