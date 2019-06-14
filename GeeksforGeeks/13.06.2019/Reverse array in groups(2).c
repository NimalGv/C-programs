#include<stdio.h>
#include<stdlib.h>

int main(){
    int testcase, size, group, mid, *array, start;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        scanf("%d", &group);
        array=(int *)malloc(size*sizeof(int));
        for(int i=0; i<size; i++)
            scanf("%d", &array[i]) ;
        for(int i=0; i<size; i+=group){
            if(i+group-1 >= size)
                for(int j=size-1; j>=i; j--)
                    printf("%d ", array[j]);
            else
                for(int j=i+group-1; j>=i; j--)
                    printf("%d ", array[j]);
        }

    }
    return 0;
}
