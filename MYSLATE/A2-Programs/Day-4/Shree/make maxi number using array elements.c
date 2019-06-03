#include<stdio.h>
// 12 456

int power(int count)
{
  int pow=1, ctr;
  for(ctr = 0; ctr < count; ctr++)
     pow=pow * 10;

     return pow;

}
int nod(int num)
{
    int len =0;
    while(num)
    {
        num =num / 10;
        len++;
    }
    return len;
}
int combine (int inp1, int inp2)
{
int len2,pow2;
     len2 = nod(inp2);
   pow2 = power(len2);
   return inp1 * pow2 + inp2;
}
int comparator(int inp1, int inp2)
{
   int combi1, combi2;
   combi1 = combine(inp1, inp2);
   combi2 = combine(inp2, inp1);
   if(combi2 > combi1) return 1;
   return 0;
}



int main()
{
 int arr[] = {18,23,12,30,1, 6,72,5,8,19}, size, outer, inner, temp, index;
size = sizeof(arr) / sizeof(int);
 for(index =0; index < size; printf("%d ", arr[index++]));

for(outer = 0; outer < size; outer++)
{
    for(inner = 0; inner < size - 1; inner++)
    if(comparator(arr[inner], arr[inner+1]) == 1)
 {
     temp = arr[inner];
     arr[inner] = arr[inner+1];
     arr[inner+1] = temp;

 }
  for(index =0, printf("\n"); index < size; printf("%d ", arr[index++]));
}

return 0;
}
