#include<stdio.h>

typedef struct time
{
    int hours;
    int minutes;
    int seconds;
} TIME;


void printTime(TIME gt);
void getTime(TIME *gt);
TIME addTimeSeconds(TIME, int);
TIME subTimeSeconds(TIME, int);
TIME addTimeMinutes(TIME, int);
TIME subTimeMinutes(TIME, int);
TIME addTimeHours(TIME, int);
TIME subTimeHours(TIME, int);
TIME addTimeTime();
TIME subTimeTime();
