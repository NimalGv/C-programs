#include<stdio.h>
#include<string.h>


int main()
{
int width, prec, offset, row, n;
n = 10;
char *stars;
//scanf("%d", &n);
stars =(char *) malloc((n*2)*sizeof(char));
memset(stars,'*', n*2);
stars[n*2-1] = NULL;
for(row=0, width =n, prec = 1, offset = row * row; row < n;
                 row++, width++, prec+=2, offset = row * row)
printf("%*.*s\n", width, prec, stars);
return 0;

}
