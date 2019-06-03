#include<stdio.h>
#include<limits.h>


int main()
{

   int arr[] = {44,13,30,72,22,44,42,67,31,19,86,98,11,12,33};
// int arr[] = {5,4,3,2,1};
    int index, size, minval, minpos, temp, begin, inner;
    size = sizeof(arr) / sizeof(arr[0]);
        for(index = 0; index < size; printf("%d ", arr[index++]));
   for(begin = 0,minval = INT_MAX,    minpos= -1;
              begin < size;
                         begin++,minval = INT_MAX,    minpos= -1)
   {
    for(inner=begin ;  inner<size; inner++)
    {

         if(arr[inner] < minval)
         {
              minval = arr[inner];
              minpos = inner;
         }
    }
         temp = arr[begin];
         arr[begin] = arr[minpos];
         arr[minpos] = temp;
         for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));
   }

return 0;
}
