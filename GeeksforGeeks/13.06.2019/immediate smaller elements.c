#include<stdio.h>
#include<stdlib.h>

int main(){
    int testcase, size, *array;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        array=(int *)malloc(size*sizeof(int));
        for(int i=0; i<size; i++)
            scanf("%d", &array[i]);
        for(int i=0; i<size-1; i++){
            if(array[i]>array[i+1])
                printf("%d ", array[i+1]);
            else
                printf("-1 ");
        }
        printf("-1");
    }

    return 0;
}
