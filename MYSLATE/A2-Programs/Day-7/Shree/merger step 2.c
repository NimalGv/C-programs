#include<stdio.h>

int * merger(int arr[], int start, int mid, int end)
{
int ind1, ind2, size,newind, *newArr=NULL, index;
newind = 0;
ind1 = start;
ind2  = mid + 1;
size = (end - start)+1;
newArr = (int *) malloc(sizeof(int)* (size));
while(ind1 <=mid  && ind2 <= end)
{
if(arr[ind1] < arr[ind2])
    newArr[newind++] = arr[ind1++];
else
   newArr[newind++] = arr[ind2++];
   }
   while(ind1 <= mid)
      newArr[newind++] = arr[ind1++];
     while(ind2 <= end)
        newArr[newind++] = arr[ind2++];
        for(index = start, newind = 0; index <= end; index++, newind++)
            arr[index] = newArr[newind];

        return arr;
}


int main()
{
   int arr[] = {1,3,5,7,8,9,10, 6,14,17,19,33, 12,15,17,19,23,27,29,36,39,23,34,56,78,90}, index;
    int size;
    size = sizeof(arr) / sizeof(int);
   merger(arr, 7, 11,20);
   for(index = 0; index < size; printf("%d ", arr[index++]));


}
