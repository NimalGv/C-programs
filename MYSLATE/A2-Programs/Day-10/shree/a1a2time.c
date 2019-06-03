#include "a1a2time.h"


int toSeconds(TIME gt)
{
   return  gt.hours * 3600 + gt.minutes * 60 + gt.seconds;
}
void printTime(TIME gt)
{
   printf("%d:%d:%d\n", gt.hours, gt.minutes, gt.seconds);
}
void getTime(TIME* gt)
{
scanf("%d:%d:%d", & gt->hours, &gt->minutes, &gt->seconds);
}
TIME addTimeSeconds(TIME gt, int s)
{
   TIME temp;
   int inseconds;
   inseconds = toSeconds(gt);
   inseconds += s;
   temp.hours = inseconds / 3600;
   temp.minutes = (inseconds % 3600) / 60;
   temp.seconds = (inseconds % 3600) % 60;
   return temp;
}
TIME subTimeSeconds(TIME gt, int  s)
{
TIME temp;
   int inseconds;
   inseconds = toSeconds(gt);
   inseconds -= s;
   temp.hours = inseconds / 3600;
   temp.minutes = (inseconds % 3600) / 60;
   temp.seconds = (inseconds % 3600) % 60;
   return temp;

}
TIME addTimeMinutes(TIME gt, int m)
{
   TIME temp;
   int inseconds;
   inseconds = toSeconds(gt);
   inseconds += (m* 60);
   temp.hours = inseconds / 3600;
   temp.minutes = (inseconds % 3600) / 60;
   temp.seconds = (inseconds % 3600) % 60;
   return temp;
}
TIME subTimeMinutes(TIME gt , int m)
{
TIME temp;
   int inseconds;
   inseconds = toSeconds(gt);
   inseconds -= (m * 60);
   temp.hours = inseconds / 3600;
   temp.minutes = (inseconds % 3600) / 60;
   temp.seconds = (inseconds % 3600) % 60;
   return temp;
}

TIME addTimeHours(TIME gt, int h)
{
TIME temp;
   int inseconds;
   inseconds = toSeconds(gt);
   inseconds += (h * 3600);
   temp.hours = inseconds / 3600;
   temp.minutes = (inseconds % 3600) / 60;
   temp.seconds = (inseconds % 3600) % 60;
   return temp;

}
TIME subTimeHours(TIME gt, int h)
{
      TIME temp;
   int inseconds;
   inseconds = toSeconds(gt);
   inseconds -= (h * 3600);
   temp.hours = inseconds / 3600;
   temp.minutes = (inseconds % 3600) / 60;
   temp.seconds = (inseconds % 3600) % 60;
   return temp;

}
TIME subTimeTime(TIME gt1, TIME gt2)

{
      TIME temp;
   int inseconds1, inseconds2, diff;
   inseconds1 = toSeconds(gt1);
   inseconds2 = toSeconds(gt2);

   diff = inseconds1 - inseconds2;
   if(diff < 0)
    diff = -diff;
   temp.hours = diff / 3600;
   temp.minutes = (diff % 3600) / 60;
   temp.seconds = (diff % 3600) % 60;
   return temp;


}


TIME addTimeTime(TIME gt1, TIME gt2)

{
      TIME temp;
   int inseconds1, inseconds2, sum;
   inseconds1 = toSeconds(gt1);
   inseconds2 = toSeconds(gt2);

   sum = inseconds1 +  inseconds2;
   temp.hours = sum / 3600;
   temp.minutes = (sum % 3600) / 60;
   temp.seconds = (sum % 3600) % 60;
   return temp;


}
