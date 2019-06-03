#include<stdio.h>
int *merger(int *, int, int ,int);
int *mergeSort(int arr[], int start, int end)
{
    int mid;
    if(start>=end) return;
    mid = (start+end)/2;
    mergeSort(arr,start, mid);
    mergeSort(arr,mid+1,end);
    merger(arr, start, mid, end);


}

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
        free(newArr);
        return arr;
}


int main()
{
   int arr[] = {10,30,40,11,33,49, 68,11,12,30, 6, 78, 15, 51,3, 45, 33, 78, 44, 190}, index;
    int size;
    size = sizeof(arr) / sizeof(int);
    for(index = 0; index < size; printf("%d ", arr[index++]));
   mergeSort(arr, 0, size-1);
   for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));


}
