#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

char table[][5]={
                  {'D', 'L', 'A', 'B', 'L'},
                  {'C', 'A', 'P', 'A', 'M'},
                  {'O', 'I', 'M', 'L', 'I'},
                  {'P', 'I', 'S', 'O', 'N'},
                  {'N', 'I', 'M', 'G', 'V'}, };

char key[]="NIMAL";

int found=0;


void findString(int row, int column, int keyIndex){


    //Left
    if(column-1 >= 0 && table[row][column-1]==key[keyIndex+1] && found==0){
        findString(row, column-1, keyIndex+1);
    }
    //UpLeft
    if(row-1 >= 0 && column-1 >=0 && table[row-1][column-1]==key[keyIndex+1] && found==0){
        findString(row-1, column-1, keyIndex+1);
    }
    //Up
    if(row-1 >= 0 && table[row-1][column]==key[keyIndex+1] && found==0){
        findString(row-1, column, keyIndex+1);
    }
    //UpRight
    if(row-1 >= 0 && column+1 < SIZE && table[row-1][column+1]==key[keyIndex+1] && found==0){
        findString(row-1, column+1, keyIndex+1);
    }
    //Right
    if(column+1 < SIZE && table[row][column+1]==key[keyIndex+1] && found==0){
        findString(row, column+1, keyIndex+1);
    }
    //DownRight
    if(row+1 < SIZE && column+1 < SIZE && table[row+1][column+1]==key[keyIndex+1] && found==0){
        findString(row+1, column+1, keyIndex+1);
    }
    //Down
    if(row+1 < SIZE && table[row+1][column]==key[keyIndex+1] && found==0){
        findString(row+1, column, keyIndex+1);
    }
    //DownLeft
    if(row+1 < SIZE && column-1 >= 0 && table[row+1][column-1]==key[keyIndex+1] && found==0){
        findString(row+1, column-1, keyIndex+1);
    }

    if(key[keyIndex+1]=='\0'){
        printf("Found");
        found=1;
    }
}

int main()
{
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            if(table[i][j]==key[0])
                findString(i, j, 0);

    return 0;
}
