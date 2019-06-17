#include <stdio.h>
#include <stdlib.h>

int main(){
    int testcase, size, winsize, *array, *window, count=0;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d %d", &size, &winsize);
        array=(int*)malloc(size*sizeof(int));
        for(int i=0; i<size; scanf("%d", &array[i++]));
        count=0;
        int max=-1;

        for(int i=0; i<size; i++)
            if(max<array[i])
                max=array[i];

        int* window=(int*)calloc(max, sizeof(int));

        for(int i=0; i<size-winsize+1; i++){
            for(int j=0; j<winsize; j++){
                if(window[array[i+j]-1]==0){
                    window[array[i+j]-1]=1;
                    count++;
                }
            }
            for(int j=0; j<winsize; window[array[i+j]-1]=0, j++);
            printf("%d ", count);
            count=0;

        }
        printf("\n");
    }
    return 0;
}
