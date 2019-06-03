#include<stdio.h>
#include<conio.h>
int main()
{
 int * ptr;
 int no_ele,ind;
 clrscr();
 printf("Enter the no of ele : ");
 scanf("%d",&no_ele);
// ptr=(int*)malloc(no_ele * sizeof(int));
 ptr=(int*)calloc(no_ele , sizeof(int));
 for(ind= 0 ;ind< no_ele; printf("%d ",ptr[ind++]));

 getch();
 return 0;
}