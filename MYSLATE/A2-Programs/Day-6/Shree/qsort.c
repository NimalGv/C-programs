#include<stdio.h>
// 10 : 04

void printArr(int arr[], int start, int end)
{
    int ind;
    for(ind = start, printf("\n"); ind <= end; printf("%d ", arr[ind++]));
    fflush(stdout);
    getch();


}

int swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}


int qSort(int arr[], int start, int end)
{
         int getlarge, getsmall, pivot;
         if(start>=end) return;
     pivot = arr[end];
     getlarge = start;
     getsmall = end - 1;
while( getlarge <= getsmall )
{
     while( arr[getlarge] < pivot )
         getlarge++;
    while( arr[getsmall] > pivot )
         getsmall--;
         if(getlarge < getsmall)
            swap(arr, getlarge, getsmall);

}
//if(arr[getlarge] > pivot)
swap(arr, getlarge, end);

 qSort(arr, start, getlarge-1);
 printArr(arr, start, end);
 qSort(arr, getlarge+1, end);
 printArr(arr, start, end);
return 0;
}


int main()
{
     int arr[]  = {34,78, 23, 12, 18, 19, 60, 45, 89, 20, 59, 53, 15, 51, 42, 60, 48};
     int index, size;
     size = sizeof(arr) / sizeof(int);
     for(index = 0; index < size; printf("%d ", arr[index++]));
     fflush(stdout);
     getch();
     qSort(arr, 0, size - 1);
 for(index = 0, printf("\n"); index < size; printf("%d ", arr[index++]));


return 0;
}
