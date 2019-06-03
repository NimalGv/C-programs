#include<stdio.h>
#include"a1a2time.c"


int main()
{
 TIME now, later;
 getTime(&now);
 printTime(now);
 later = addTimeHours(now, 5);
 printTime(later);

 return 0;

}
