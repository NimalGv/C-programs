#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void reversegroup(int *array, int size, int start, int group){
    int half=group/2;
    int end;
    end=start+group-1;
    if((size-start+1)<=group){
        half=(size%group)/2;
        end=size-1;
    }
    for(int i=start, k=0; i<half+start; i++, k++)
        swap(&array[i], &array[end-k]);
}

int main(){
    int testcase, size, group, mid, *array, start;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        scanf("%d", &group);
        array=(int *)malloc(size*sizeof(int));
        for(int i=0; i<size; i++)
            scanf("%d", &array[i]) ;
        for(int i=0; i<size; i+=group)
            reversegroup(array, size, i, group);
        printf("\n");
        for(int i=0; i<size; printf("%d ", array[i++]));

    }

    return 0;
}
