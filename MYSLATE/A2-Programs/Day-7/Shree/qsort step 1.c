#include<stdio.h>
// 9:33

void swap(int arr[], int p1, int p2)
{
    int temp;
    temp =arr[p1];
    arr[p1] = arr[p2];
    arr[p2] = temp;
}
int main()
{
   int arr[] = {10,19,29,45,6,18,17,24,42,15,51,18,60,70,5,95,90,70,54,36};
  int size, start, end, left, right, temp, pivot, index;

  size = sizeof(arr) / sizeof(int);

  start = 0;
  end =size-1;
   pivot = arr[end];

   left = start;
   right = end - 1;
   for(index = 0; index < size; printf("%d ", arr[index++]));
   while(left <= right)
   {
   while(arr[left] < pivot)
        left++;
   while(right >= start && arr[right] >pivot)
       right --;
   if(left < right)
       swap(arr, left, right);
       }
      for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));



return 0;
}

