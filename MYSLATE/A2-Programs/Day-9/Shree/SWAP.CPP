#include<stdio.h>
#include<conio.h>
swap(int inp1,int inp2)
{
   int temp ;
   temp = inp1;
   inp1= inp2 ;
   inp2 =temp;
}
swapByRef(int *inp1,int * inp2)
{
   int temp ;
   temp = *inp1;
   *inp1= *inp2 ;
   *inp2 =temp;
}
swap_REF_VAR(int &inp1,int &inp2)
{
   int temp ;
   temp = inp1;
   inp1= inp2 ;
   inp2 =temp;
}
int main()
{
 int num1=10,num2=20;
 clrscr();
 printf("Values before Swapping num1 : %d  num2 : %d\n",num1,num2);
 swap(num1,num2);
 printf("Values after Swapping num1 : %d  num2 : %d\n",num1,num2);
 printf("Values before Swapping by REF num1 : %d  num2 : %d\n",num1,num2);
 swapByRef(&num1,&num2);
 printf("Values after Swapping by REF num1 : %d  num2 : %d\n",num1,num2);
 printf("Values before Swapping by REF VAR num1 : %d  num2 : %d\n",num1,num2);
 swap_REF_VAR(num1,num2);
 printf("Values after Swapping by REF VAR num1 : %d  num2 : %d\n",num1,num2);


 getch();
 return 0 ;
}


