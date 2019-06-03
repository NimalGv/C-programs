#include<stdio.h>
#include<conio.h>

int main(int argc, char *argv[])
{
int ctr;
clrscr();
printf("%d\n\n\n\n", argc);
for(ctr = 0; ctr < argc; ctr++)
   printf("%u\t", argv+ctr);
for(ctr = 0, printf("\n\n"); ctr < argc; ctr++)
   printf("%u\t", &argv[ctr]);

for(ctr = 0, printf("\n\n"); ctr < argc; ctr++)
   printf("%u\t", argv[ctr]);
for(ctr = 0,printf("\n\n"); ctr < argc; ctr++)
  printf("%s ", argv[ctr]);

getch();
return 0;
}
