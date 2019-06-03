#include <stdio.h>

findTreasure(int treasure[][5], int rowcol){
    int row=rowcol/10;
    int col=rowcol%10;
    if(treasure[row-1][col-1]==rowcol){
        printf("%d", rowcol);
        return 0;
    }
    printf("%d ", rowcol);
    findTreasure(treasure, treasure[row-1][col-1]);
}

int main(){
    int treasure[5][5]={
                        {34, 21, 32, 41, 25},
                        {14, 42, 43, 14, 31},
                        {54, 45, 52, 42, 23},
                        {33, 15, 51, 31, 35},
                        {21, 52, 33, 54, 23}
                        };
    findTreasure(treasure, 11);
    return 0;
}
