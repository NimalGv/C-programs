#include<stdio.h>
// 10:00 10:16
#define printArr(x, y, z)   for(z = 0; z < y; printf("%d ", x[z++]));
#define printArrln(x, y, z)   for(z = 0, printf("\n"); z < y; printf("%d ", x[z++]));

void swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}
int main()
{

   int arr []  = {12, 67, 10, 19, 35, 45, 90, 11, 27, 28, 6, 19, 91, 33, 77, 55, 22};
   int outer, inner, index, size;

   size = sizeof(arr) / sizeof(int);
 printArr(arr, size, index);
   for(outer = 0; outer < size/2; outer++)
   {
      for(inner = 1; inner < size - (outer+2) ; inner+=2)
         if(arr[inner] > arr[inner+2])
           swap(arr, inner, inner+2);
   }
printArrln(arr, size, index);

return 0;
}
