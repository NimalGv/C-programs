#include<stdio.h>
#include<limits.h>
#include<malloc.h>

int main(){

    int size, *array, window_size, max_val;
    scanf("%d", &size);
    array=(int *)malloc(size*sizeof(int));
    max_val=0;

    for(int i=0; i<size; i++)
        scanf("%d", &array[i]);

    scanf("%d", &window_size);

    for(int i=0; i<size-window_size+1; i++){

        for(int run=0, start=i; run<window_size; run++, start++){

            if(max_val<array[start]){
                //printf("%d\t%d\n", max_val, array[start]);
                max_val=array[start];
                //printf("%d\t%d\n", max_val, array[start]);

            }

        }
        printf("%d ", max_val);

    }
    printf("\n\n");
    for(int i=0; i<size; i++)
        printf("%d ", array[i]);

    return 0;
}
