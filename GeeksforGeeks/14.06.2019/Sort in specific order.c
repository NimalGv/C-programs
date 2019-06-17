#include<stdio.h>
#include<stdlib.h>

int oddlimit;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int *array, int start, int end){
    int pivot=array[end];
    int i=-1;
    for(int j=0; j<end; j++){
        if(array[j]>pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[end]);
    return (i+1);
}


quicksort(int *array, int start, int end){
     if(start<end){
         int point=partition(array, start, end);
         quicksort(array, start, point-1);
         quicksort(array, point+1, end);
     }
 }

 int partition1(int *array, int start, int end){
    int pivot=array[end];
    int i=-1;
    for(int j=0; j<end; j++){
        if(array[j]<=pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[end]);
    return (i+1);
}


quicksort1(int *array, int start, int end){
     if(start<end){
         int point=partition1(array, start, end);
         quicksort(array, start, point-1);
         quicksort(array, point+1, end);
     }
 }

int main(){
    int size, testcase, odd=0;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        int *array=(int*)malloc(size*sizeof(int));
        int *temp=(int*)malloc(size*sizeof(int));
        int first=0, end=size-1;
        for(int i=0; i<size; scanf("%d", &array[i++]));
        for(int i=0; i<size; i++){
           if(array[i]%2==0){
                temp[end--]=array[i];
           }else{
                temp[first++]=array[i];
                odd++;
           }
        }
        for(int i=0; i<size; printf("%d ", temp[i++]));
        printf("\n%d\n", odd);
        int limit=odd-1;
        quicksort(temp, 0, limit);
        printf("\nodd");
        for(int i=0; i<size; printf("%d ", temp[i++]));
        quicksort1(temp, odd, size-1);
        printf("\neven");
        for(int i=0; i<size; printf("%d ", temp[i++]));
        printf("\n");
    }
    return 0;
}
