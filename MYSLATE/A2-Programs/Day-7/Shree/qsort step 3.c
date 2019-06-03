#include<stdio.h>
// 9:33 10:06

void swap(int arr[], int p1, int p2)
{
    int temp;
    temp =arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}
int *quickSort(int arr[], int start, int end)
{
    int left, right, pivot;
    if(start>=end) return;
   pivot = arr[end];
   left = start;
   right = end - 1;
   while(left <= right)
   {
   while(arr[left] < pivot)
        left++;
   while(right >= start && arr[right] >=pivot)
       right --;
   if(left < right)
       swap(arr, left, right);
       }
       if(right < start)
            swap(arr, start, end);
       else if(left!= end)
            swap(arr,left, end);
            quickSort(arr, start, left-1);
            quickSort(arr, left + 1, end);
return arr;
}
int main()
{
//int arr[] = {10,19,29,45,6,18,17,24,42,15,51,18,60,70,5,95,90,70,54,36};
    // int arr[] = {10,19,29,45,6,18,17,24,42,15,51,18,60,70,5,95,90,70,54,360};
 //int arr[] = {10,19,29,45,6,18,17,24,42,15,51,18,60,70,5,95,90,70,54,3};
//int arr[] = {34, 89, 14, 20, 28, 16, 100, 6};
int arr[] = {3,1,2,1};
    int size, start, end, left, right, temp, pivot, index;

  size = sizeof(arr) / sizeof(int);



   for(index = 0; index < size; printf("%d ", arr[index++]));
   quickSort(arr, 0, size -1 );
      for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));



return 0;
}

