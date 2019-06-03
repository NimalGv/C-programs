#include<stdio.h>
#include<string.h>


int main()
{
int width, prec, offset, row, n;
//char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/*printf("[%10.3d]\n", 12345);
printf("[%10.3f]\n", 12.34557);
printf("[%10.5s]\n", "Sridhar Arumugasamy");
*/
char *stars=NULL;
scanf("%d", &n);
stars =(char *) malloc((n*2)*sizeof(char));
memset(stars,'*', n*2);
stars[n*2-1] = NULL;
for(row=0, width =n, prec = 1, offset = row * row; row < n;
                 row++, width++, prec+=2, offset = row * row)
printf("%*.*s\n", width, prec, stars);
/*printf("%6.3s\n", alphabets+1);
printf("%7.5s\n", alphabets+4);
printf("%8.7s\n", alphabets+9);
printf("%9.9s\n", alphabets+16);*/



return 0;

}
