#include<stdio.h>
#include<stdlib.h>

int leader(int element, int start, int array[], int size){
    for(int i=start; i<size; i++)
        if(element<array[i])
            return 0;
    return 1;
}

int main(){
    int testcase, size, *array;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        array=(int *)malloc(size*sizeof(int));
        for(int i=0; i<size; i++)
            scanf("%d", &array[i]);
        for(int i=0; i<size; i++)
            if(leader(array[i], i+1, array, size))
                printf("%d ", array[i]);
    }


    return 0;
}
