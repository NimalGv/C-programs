#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
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

        mergeSort(array, 0, size-1);

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
