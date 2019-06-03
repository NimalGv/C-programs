#include<stdio.h>

int main()
{
    int n, row, col, startnum;
n = 11;
    for(row = 1; row <= n; row+=2, printf("\n"))
    {
        for(col = 1, startnum = (row - 1) * n + 1; col <= n; col++)
           printf("%02d ", startnum++);

    }
   for(row = (n % 2 == 0 ? n : n-1); row > 0; row-=2, printf("\n"))
        {
        for(col = 1, startnum = (row - 1) * n + 1; col <= n; col++)
           printf("%02d ", startnum++);

    }
}
