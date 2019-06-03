#include<stdio.h>


int main()
{
int width, prec, offset, row;
char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
/*printf("[%10.3d]\n", 12345);
printf("[%10.3f]\n", 12.34557);
printf("[%10.5s]\n", "Sridhar Arumugasamy");
*/
for(row=0, width =5, prec = 1, offset = row * row; row < 5;
                 row++, width++, prec+=2, offset = row * row)
printf("%*.*s\n", width, prec, alphabets+offset);
/*printf("%6.3s\n", alphabets+1);
printf("%7.5s\n", alphabets+4);
printf("%8.7s\n", alphabets+9);
printf("%9.9s\n", alphabets+16);*/



return 0;

}
