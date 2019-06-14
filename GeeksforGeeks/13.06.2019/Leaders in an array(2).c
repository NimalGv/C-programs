#include<stdio.h>
#include<stdlib.h>

//start from end of the array

int main(){
    int testcase, *array, *leader, size, leaderIndex;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        array=(int *)malloc(size*sizeof(int));
        leader=(int *)calloc(size, sizeof(int));
        for(int i=0; i<size; i++)
            scanf("%d", &array[i]);
        leaderIndex=size-1;
        leader[leaderIndex]=1;
        for(int i=size-2; i>=0; i--){
            if(array[i]>=array[leaderIndex]){
                leader[i]=1;
                leaderIndex=i;
            }
        }
        for(int i=0; i<size; i++)
            if(leader[i]==1)
                printf("%d ", array[i]);
        printf("\n");

    }

    return 0;
}
