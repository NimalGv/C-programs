// 9: 46 9:56

#include<stdio.h>

#define n 5
int main()
{
    int m1[n][n] = {
    {1,2,3,4,5,},
    {6,7,8,9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}
                       }, m2[n][n] = {
    {5,10,15,20,25},
    {4,9,14,19,24},
    {3,8,13,18,23},
    {2,7,12,17,22},
    {1,6,11,16,21}
                       };
int m1Row, m2Row, m1Col, m2Col;
                       //90 Degree Verification


                       for(m1Row = 0; m1Row< n; m1Row++)
                       {
                           for(m1Col = 0; m1Col < n; m1Col++)
                                if(m1[m1Row][m1Col] != m2[m1Col][n-m1Row-1]) break;

                       }
if(m1Row == n && m1Col == n) printf("Yes");
 //180 Degree Verification


                       for(m1Row = 0; m1Row< n; m1Row++)
                       {
                           for(m1Col = 0; m1Col < n; m1Col++)
                                if(m1[m1Row][m1Col] != m2[n - m1Row - 1][n-m1Col - 1]) break;

                       }
if(m1Row == n && m1Col == n) printf("Yes");
//270  Degree Verification


                       for(m1Row = 0; m1Row< n; m1Row++)
                       {
                           for(m1Col = 0; m1Col < n; m1Col++)
                                if(m1[m1Row][m1Col] != m2[n - m1Col -1 ][m1Row]) break;

                       }
if(m1Row == n && m1Col == n) printf("Yes");
return 0;
}
