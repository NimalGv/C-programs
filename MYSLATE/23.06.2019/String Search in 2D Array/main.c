#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define STRINGLEN 2

char table[][SIZE]={
                  {'D', 'L', 'A', 'B', 'L'},
                  {'C', 'A', 'P', 'A', 'M'},
                  {'O', 'I', 'M', 'L', 'I'},
                  {'P', 'I', 'S', 'O', 'N'},
                  {'N', 'I', 'M', 'G', 'V'}, };

int pattern[SIZE][SIZE];

char key[]="ML";

int found=0;

void printPattern(){
    printf("\n");
    for(int i=0; i<SIZE; printf("\n"), i++)
        for(int j=0; j<SIZE; printf("%d ", pattern[i][j]), j++);
    printf("\n");
}


void findString(int row, int column, int keyIndex){

    printf("%c ", key[keyIndex]);

    if(key[STRINGLEN-1]==key[keyIndex]){
        printPattern();
        //found=1;
    }
   //Left
   if(column-1 >= 0 && table[row][column-1]==key[keyIndex+1] && !found){
        pattern[row][column-1]=1;
        findString(row, column-1, keyIndex+1);
        pattern[row][column-1]=0;
   }
   //Up
   if(row-1 >= 0 && table[row-1][column]==key[keyIndex+1] && !found){
        pattern[row-1][column]=1;
        findString(row-1, column, keyIndex+1);
        pattern[row-1][column]=0;
   }
   //Down
   if(row+1 < SIZE && table[row+1][column]==key[keyIndex+1] && !found){
        pattern[row+1][column]=1;
        findString(row+1, column, keyIndex+1);
        pattern[row+1][column]=0;
   }
   //Right
   if(column+1 < SIZE && table[row][column+1]==key[keyIndex+1] && !found){
        pattern[row][column+1]=1;
        findString(row, column+1, keyIndex+1);
        pattern[row][column+1]=0;
   }
   //Up Right
   if(row-1 >= 0 && column+1 < SIZE && table[row-1][column+1]==key[keyIndex+1] && !found){
        pattern[row-1][column+1]=1;
        findString(row-1, column+1, keyIndex+1);
        pattern[row-1][column+1]=0;
   }
   //Up Left
   if(row-1 >= 0 && column-1 >= 0 && table[row-1][column-1]==key[keyIndex+1] && !found){
        pattern[row-1][column-1]=1;
        findString(row-1, column-1, keyIndex+1);
        pattern[row-1][column-1]=0;
   }
   //Down Right
   if(row+1 < SIZE && column+1 < SIZE && table[row+1][column+1]==key[keyIndex+1] && !found){
        pattern[row+1][column+1]=1;
        findString(row+1, column+1, keyIndex+1);
        pattern[row+1][column+1]=0;
   }
   //Down Left
   if(row+1 < SIZE && column-1 >= 0 && table[row+1][column-1]==key[keyIndex+1] && !found){
        pattern[row+1][column-1]=1;
        findString(row+1, column-1, keyIndex+1);
        pattern[row+1][column-1]=0;
   }

}

int main(){

    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(table[i][j]==key[0]){
                pattern[i][j]=1;
                findString(i, j, 0);
                pattern[i][j]=0;
            }
        }
    }

    return 0;
}
