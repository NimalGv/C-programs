#include<stdio.h>
#include<string.h>
int main()
{
   char temp[2000];
   char ** words=NULL;
   int how_many,ctr,len;
   scanf("%d",&how_many);
   words = (char**)calloc(how_many,sizeof(char*));
   for(ctr = 0 ; ctr < how_many; ctr++)
   {
       scanf("%s",temp);
       len = strlen(temp);
       words[ctr] = (char*)malloc(len+1);
       strcpy(words[ctr],temp);
   }

    return 0 ;
}
