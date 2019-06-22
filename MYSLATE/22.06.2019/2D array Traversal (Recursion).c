#include <stdio.h>


int array[][5]={{1, 0, 1, 0, 1},
                {1, 1, 1, 1, 1},
                {1, 0, 0, 1, 0},
                {1, 1, 10, 1, 1},
                {1, 1, 1, 0, 1}};

int visited[5][5];

int found=0;

void print(){

    for(int i=0; i<5; printf("\n"), i++)
        for(int j=0; j<5; printf("%d ", visited[i][j]), j++) ;
        printf("\n");
}

int count1(){
    int count=0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(visited[i][j]==1)
                count++;
    return count;
}



void path(int row, int column){

    visited[row][column]=1;
    printf("(%d %d)\n", row, column);
    print();

    if(array[row][column]==10)
        found=1;


    //Left
    if(column-1 >=0 && visited[row][column-1]!=1 && array[row][column-1]!=0 && !found)
        path(row, column-1);

    //Right
    if(column+1 < 5 && visited[row][column+1]!=1 && array[row][column+1]!=0 && !found)
        path(row, column+1);

    //Up
    if(row-1 >= 0 && visited[row-1][column]!=1 && array[row-1][column]!=0 && !found)
        path(row-1, column);

    //down
    if(row+1 < 5 && visited[row+1][column]!=1 && array[row+1][column]!=0 && !found)
        path(row+1, column);

    if(found){
        printf("Count:%d\n", count1());
    }

    //printf("\n");
    visited[row][column]=0;
    found=0;
}


int main(){

    path(0,0);
    print();

    return 0;
}
