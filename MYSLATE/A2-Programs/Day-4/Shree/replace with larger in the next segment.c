#include<stdio.h>
#include<limits.h>


int main()
{
     int arr[] = {10, 16, 17, 90, 56, 78, 8, 64, 88, 67, 283, 91, 100, 109, 143, 210, 30, 186, 203, 186, 98 };
      int size, index, max;


      size = sizeof(arr) / sizeof(int);
      for(index = 0;index < size; printf("%d ", arr[index++]));
      max = arr[size-1];
      for(index = size - 2; index >=0; index--)
      {
          if(arr[index] > max)
             max= arr[index];
             else
             arr[index] = max;

      }
        for(index = 0, printf("\n");index < size; printf("%d ", arr[index++]));
      return 0;
}
