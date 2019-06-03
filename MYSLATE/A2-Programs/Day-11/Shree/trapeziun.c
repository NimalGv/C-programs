#include<stdio.h>

int main()
{
    int n, row, col, startnum, num = 1, spacectr, spaces=0;
    n= 9;
    for(row = n ; row >= 1;  spaces++, row--, printf("\n"))
    {
        for(spacectr = 0; spacectr < spaces; spacectr++)
            printf("   ");
         for(col = 1; col <= row; col++ )
             printf("%02d ", num++);
      for(col = 1, startnum = (n * (n + 1) - (num) + 2); col <= row; col++ )
             printf("%02d ", startnum++);

    }

}
