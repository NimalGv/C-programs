#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMN 4
#define ROW 4
#define UP 8
#define LEFT  4
#define DOWN 2
#define RIGHT  6
#define ESC 5

int array[][COLUMN]={
                        {8, 4, 8, 8},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0},
                        {8, 2, 0, 0} };


void add(){
        int row, column, number;
        srand(time(0));
        if(rand()%2==0)
                number=2;
        else
                number=4;
        while(1){
        row=rand()%ROW;
        column=rand()%COLUMN;
                if(array[row][column]==0) {
                        array[row][column]=number;
                        break;
                }
        }

}

void moveUp( ){
        int position;
        for(int column=0; column<COLUMN; column++){
                for(int start=0; start<ROW-1; start++){
                        for(position=start+1; array[position][column]==0 && position <= ROW-1; position++);
                        if(position<=ROW-1){
                                if(array[start][column]==0){
                                        array[start][column]=array[position][column];
                                        array[position][column]=0;
                                        start--;
                                }else if(array[start][column]==array[position][column]){
                                        array[start][column]*=2;
                                        array[position][column]=0;
                                }else{
                                        array[start+1][column]=array[position][column];
                                        if(start+1 != position)
                                                array[position][column]=0;
                                }
                        }else
                                break;
                }
        }
}

void moveDown( ){
        int position;
        for(int column=0; column<COLUMN; column++){
                for(int start=ROW-1; start>0; start--){
                        for(position=start-1; array[position][column]==0 && position>=0; position--);
                        if(position>=0){
                                if(array[start][column]==0){
                                        array[start][column]=array[position][column];
                                        array[position][column]=0;
                                        start++;
                                }else if(array[start][column]==array[position][column]){
                                        array[start][column]*=2;
                                        array[position][column]=0;
                                }else{
                                        array[start-1][column]=array[position][column];
                                        if(start-1 != position)
                                                array[position][column]=0;
                                }
                        }else
                                break;
                }
        }
}

void moveRight( ){
        int position;
        for(int row=0; row<ROW; row++){
                for(int start=COLUMN-1; start>0; start--){
                        for(position=start-1; array[row][position]==0 && position>=0; position--);
                        if(position>=0){
                                if(array[row][start]==0){
                                        array[row][start]=array[row][position];
                                        array[row][position]=0;
                                        start++;
                                }else if(array[row][start]==array[row][position]){
                                        array[row][start]*=2;
                                        array[row][position]=0;
                                }else{
                                        array[row][start-1]=array[row][position];
                                        if(start-1 != position)
                                                array[row][position]=0;
                                }
                        }else
                                break;
                }
        }
}

void moveLeft( ){
        int position;
        for(int row=0; row<ROW; row++){
                for(int start=0; start<COLUMN-1; start++){
                        for(position=start+1; array[row][position]==0 && position <= COLUMN-1; position++);
                        if(position<=COLUMN-1){
                                if(array[row][start]==0){
                                        array[row][start]=array[row][position];
                                        array[row][position]=0;
                                        start--;
                                }else if(array[row][start]==array[row][position]){
                                        array[row][start]*=2;
                                        array[row][position]=0;
                                }else{
                                        array[row][start+1]=array[row][position];
                                        if(start+1 != position)
                                                array[row][position]=0;
                                }
                        }else
                                break;
                }
        }
}

void printArray( ){
        printf("\n\n");
        for(int row=0; row<ROW; printf("\n"), row++)
                for(int column=0; column<COLUMN; printf("%3d ", array[row][column++]));
        printf("\n\n");
}

int main(){
        //Have to write code for "You Loose"
        int direction;
        printArray();
        while(1){
                printf("8.UP    6.RIGHT   2.DOWN    4.LEFT\n");
                scanf("%d", &direction);
                switch(direction){
                        case UP:
                                moveUp();
                                add();
                                break;
                        case LEFT:
                                moveLeft();
                                add();
                                break;
                        case DOWN:
                                moveDown();
                                add();
                                break;
                        case RIGHT:
                                moveRight();
                                add();
                                break;
                        case ESC:
                                exit(0);
                }
                printArray();
        }
        return 0;
}
