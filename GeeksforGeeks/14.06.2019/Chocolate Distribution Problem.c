#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++){
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int testcase, size, *array, *check, m, times;
    scanf("%d", &testcase);
    while(testcase--){
        scanf("%d", &size);
        array=(int*)malloc(size*sizeof(int));

        for(int i=0; i<size; scanf("%d", &array[i++]));

        scanf("%d", &m);
        times=size-m;

        quickSort(array, 0, size-1);

        check=(int*)malloc((times+1)*sizeof(int));

        for(int i=0; i<=times; i++)
            check[i]=abs(array[i+m-1]-array[i]);

        for(int j=1; j<=times; j++)
                if(check[0]>check[j])
                    swap(&check[0], &check[j]);

        printf("%d\n", check[0]);
    }
    return 0;
}
