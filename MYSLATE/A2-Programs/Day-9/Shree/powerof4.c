#include<stdio.h>
int main()
{
    int num=1,mask=1;
   // num=0x40000000;
    if((num&(num-1))==0)
    {
        while(mask<=num)
        {
          if((num&mask)==mask)
            {
                    printf("Yes");
                     break;
            }
            mask  = mask << 2;
        }
            if(mask>num)
                printf("No");
    }
    else
        printf("Not");
    return 0 ;
}
