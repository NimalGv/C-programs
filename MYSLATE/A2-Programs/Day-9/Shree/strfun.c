#include<stdio.h>
#include"A1A2String.h"
int main()
{
   //char des[100]="Bannari Amman Institute of Technology";
  //char des[100]="BannariAmman";
  //char str[]="this is a test sentence";
  char *strptr="ABCDEFGHIJ";
  char*res;
  //char str[]="QWERTY";
  char str[]="qwerty";
//char src[]=",Sathyamangalam";
   //printf("%d",strLen(str));
  //  printf("%s\n%s",str,strCopy(des,str));
   // printf("\n%d",strComp(str,des));
     //printf("%s",strCat(des,src));
     //printf("%s",strRev(str));
      //printf("%s",strNrev(str,4));
             // printf("%s",strWordRev1(str));
             //printf("%s",strWordRev2(str));
           //  res= (char * )malloc(100);
             //strCopy(res,strptr);
             //printf("%s",res);
             //printf("\n%s",strLwr(res));
             //printf("\n%s",strUpr(res));
            //printf("\n%s",strLwr(strptr));
            //printf("%s",strChr("sentence",'l'));

            return 0 ;
}
char * strChr(char str[] ,char search)
{
    int ind;
    for(ind= 0 ; str[ind]; ind++)
        if(str[ind]==search)
         return str+ind;
    return  NULL;
}
char * strUpr(char str[])
{
   int ind;
    for(ind= 0  ;str[ind]; ind++)
    if(str[ind] >96 && str[ind]<123)
      str[ind]-=32;
    return str;

}
char * strLwr(char str[])
{
    int ind;
    for(ind= 0  ;str[ind]; ind++)
    if(str[ind] >64 && str[ind]<91)
      str[ind]+=32;
    return str;
}
char * strWordRev2(char str[])
{
    strRev(str);
    strWordRev1(str);
    return str;
}
char * strWordRev1(char str[])
{
     int st,end;
     st=0;
     end=0;
     while(1)
   {
     while(str[end]!=' '&&str[end]!=NULL)
        end++;
      strNrev(str+st,end-st);
      if(str[end]==NULL) break;
     end++;
     st=end;
   }
     return str;
}
char * strNrev(char str[],int no_of_char)
{
    int start,end;
    char temp;
    for(start = 0 , end = no_of_char-1 ; start <end; start++,end--)
     {
         temp = str[start];
         str[start] = str[end];
         str[end] = temp;
     }
    return str;
}

char * strRev(char str[])
{
    int start,end;
    char temp;
    for(start = 0 , end = strLen(str)-1 ; start <end; start++,end--)
     {
         temp = str[start];
         str[start] = str[end];
         str[end] = temp;
     }
    return str;
}
char * strCat(char des[] , char src[])
{
     strCopy(des+strLen(des) , src);
    return des;
}
int strComp(char str1[],char str2[])
{
    int ind=0;
    while(str1[ind] && str2[ind]&&str1[ind]==str2[ind])
        ind++;
    return str1[ind]-str2[ind];
}
char * strCopy( char des[] , char src[])
{
    int ind;
    for(ind = 0 ; src[ind]; ind++)
        des[ind] = src[ind] ;
    des[ind]=NULL;
    return des;
}
int strLen(char str[])
{
    int len;
   for(len = 0 ; str[len] ; len++);
   return len;
}
