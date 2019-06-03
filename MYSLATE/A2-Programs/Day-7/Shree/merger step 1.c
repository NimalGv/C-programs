#include<stdio.h>

int * merger(int arr1[], int size1, int arr2[], int size2)
{
int ind1, ind2, newind, *newArr=NULL;
ind1 = ind2 = newind = 0;
newArr = (int *) malloc(sizeof(int)* (size1+size2));
while(ind1 < size1 && ind2 < size2)
{
if(arr1[ind1] < arr2[ind2])
    newArr[newind++] = arr1[ind1++];
else
   newArr[newind++] = arr2[ind2++];
   }
   while(ind1 < size1)
      newArr[newind++] = arr1[ind1++];
     while(ind2 < size2)
        newArr[newind++] = arr2[ind2++];
        return newArr;
}


int main()
{
   int arr1[] = {10, 11, 19, 23, 28, 35}, arr2[] = {1,3,5,31}, *newArr, index;

   newArr = merger(arr1, 6, arr2, 4);
   for(index = 0; index < 10; printf("%d ", newArr[index++]));


}
