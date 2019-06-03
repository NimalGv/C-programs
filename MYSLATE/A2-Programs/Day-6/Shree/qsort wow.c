#include<stdio.h>

void swap(int arr[] , int p1, int p2)
{
    int temp;
    temp = arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}

quickSort(int arr[], int start, int end)
{
    int left, right, pivot;
    if(start<end)
    {  end = 14;

    pivot = arr[end];
    left = start;
    right = end - 1;
    while(left<=right)
    {
    while(arr[left] < pivot)
        left++;
     while(arr[right] > pivot)
            right--;
     if(left < right)
       swap(arr, left, right);
}
   if(left != end)
    swap(arr, left, end -1);
    quickSort(arr, start, left - 1);
    quickSort(arr, left+1, end);
    }
}

int main()
{
int arr[]  = {34,78, 23, 12, 18, 19, 60, 48, 58, 20, 59, 53, 15, 51, 42, 60, 89};
    // int arr[] = {34, 24, 14, 29, 30, 45, 41, 10, 48, 78, 49, 53, 59, 61, 55};
     int index, size, left,right, end, pivot;
     size = sizeof(arr) / sizeof(int);
     for(index = 0; index < size; printf("%d ", arr[index++]));

     quickSort(arr, 0, size-1);
     for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));





     }
