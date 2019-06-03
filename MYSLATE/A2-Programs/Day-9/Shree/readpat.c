#include<stdio.h>
void myPrintf(char *str)
{
    int ind;
    for( printf("\n"),ind= 0 ; str[ind]; printf("%c ",str[ind++]));
}
int main()
{

  char read[100]="1";
  char write[100];
  int ctr,sum,w_ind,ind,no_times;
  char safe;
  for(myPrintf(read),no_times = 0 ; no_times<10; no_times++)
  {
  ind= w_ind= ctr=0;
  safe = read[ind];
  while(1)
 {
  while(read[ind]==safe)
  {
      ctr++;
      ind++;
  }
    write[w_ind++]=ctr+48;
   write[w_ind++]=safe;
  if(read[ind]!=NULL)
  {
     safe = read[ind];
     ctr=0;
  }
  else break;
 }
 write[w_ind]=NULL;
 myPrintf(write);
 strcpy(read,write);
 write[0]=NULL;
 }
    return 0 ;
}
