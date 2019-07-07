#include <stdio.h>

void swap(int* a, int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int* array, int start, int end){
    int pivot=array[end];
    int i=-1;
    for(int j=0; j<end; j++){
        if(array[j]<=pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[end]);
    return i+1;
}

void sort(int* array, int start, int end){
    if(start<end){
        int point=partition(array, start, end);
        sort(array, start, point-1);
        sort(array, point+1, end);
    }
}

int find(int *array, int start, int end, int search){
    if(start<=end){
        int middle=start+(end-start)/2;
        if(array[middle]==search)
            return 1;
        else if(array[middle]>search)
            find(array, start, middle-1, search);
        else if(array[middle]<search)
            find(array, middle+1, end, search);

    }else
        return 0;
}

int main(){
	int array[]={10,9,8,7,6,5,4,3,2,1};
    int size=sizeof(array)/sizeof(int);
    sort(array, 0, size-1);
    if(find(array, 0, size-1, 11))
        printf("\nFound");
    else
        printf("\nNot Found");
    return 0;
}
