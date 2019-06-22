#include <stdio.h>
#include <stdlib.h>


int chess[][5]={{0, 1, 0, 1, 0},
                {1, 1, 0, 1, 1},
                {0, 0, 1, 1, 0},
                {0, 1, 0, 0, 1},
                {55,0, 0, 0, 1}};

int up(int row, int column){
    static int count=0;
    if(row-1 >=0 && chess[row-1][column]!=1)
        up(row-1, column);
    count++;
    return count;
}

int down(int row, int column){
    static int count=0;
    if(row+1 < 5 && chess[row+1][column]!=1)
        down(row+1, column);
    count++;
    return count;
}

int left(int row, int column){
    static int count=0;
    if(column-1 >=0 && chess[row][column-1]!=1)
        left(row, column-1);
    count++;
    return count;
}

int right(int row, int column){
    static int count=0;
    if(column+1 < 5 && chess[row][column+1]!=1)
        right(row, column+1);
    count++;
    return count;
}



void rook(int row, int column){
    printf("%d\n", up(row, column)+down(row, column)+left(row, column)+right(row, column)-4);
}

int main(){
    rook(4,0);

    return 0;
}

