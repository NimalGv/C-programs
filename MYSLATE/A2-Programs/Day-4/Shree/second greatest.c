#include<stdio.h>
#include<limits.h>


int main()
{
     int arr[] = {10, 16, 17, 90, 56, 78, 8, 64, 88, 67, 83, 91, 100, 109, 143, 2100, 30, 186, 203, 186, 298 };
      int size, index, max1, max2;


      size = sizeof(arr) / sizeof(int);

      for(index = 0,max1 = max2 = INT_MIN; index < size; index++)
      {
           if(arr[index] > max1)
           {
                max2 = max1;
                max1 = arr[index];

           } else if(arr[index] > max2)
               max2 = arr[index];

      }
     printf("%d", max2);
return 0;
}
