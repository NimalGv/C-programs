#include<stdio.h>

int main()

{
   int n , row, col, spaces, spacectr;
   // row is controlled by n
   // col is contrlled by row
   n = 9;

   for(row = 1, spaces = n - 1; row <= n; printf("\n"), row++, spaces--)
   {
       for(spacectr = 0; spacectr < spaces; spacectr++)
          printf("  ");
        for(col = 1; col <= row; col++)
            printf("%d ", col);
    for(col = row-1; col > 0 ; col--)
            printf("%d ", col);

   }
 for(row = n-1, spaces = 1; row>= 1; printf("\n"), row--, spaces++)
   {
       for(spacectr = 0; spacectr < spaces; spacectr++)
          printf("  ");
        for(col = 1; col <= row; col++)
            printf("%d ", col);
    for(col = row-1; col > 0 ; col--)
            printf("%d ", col);

   }


return 0;
}
