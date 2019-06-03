#include<stdio.h>
int main()
{
  char str[]="Bannari Amman Institute of Technology, Sathyamangalam.";
  int len=0;
  for(len = 0 ; str[len]; len++);

  printf("%d",len);

    return 0 ;
}
