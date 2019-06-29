#include <stdio.h>
#include <stdlib.h>

//int area[SIZE][SIZE];
int **area;
int **visited;
char **userArea;


void addSum(int row, int column, int r, int c){
    //left
	if(column-1 >= 0 && area[row][column-1]!=9)
		area[row][column-1]+=1;
    //up left
	if(column-1 >= 0 && row-1 >=0 && area[row-1][column-1]!=9)
		area[row-1][column-1]+=1;
	//Up
	if(row-1 >= 0 && area[row-1][column]!=9)
		area[row-1][column]+=1;
	//up right
	if(column+1 < c && row-1 >=0 && area[row-1][column+1]!=9)
		area[row-1][column+1]+=1;
	//right
	if(column+1 < c && area[row][column+1]!=9)
		area[row][column+1]+=1;
	//down right
	if(column+1 < c && row+1 < r && area[row+1][column+1]!=9)
		area[row+1][column+1]+=1;
	//down
	if(row+1 < r && area[row+1][column]!=9)
		area[row+1][column]+=1;
	//down left
    if(column-1 >= 0 && row+1 < r && area[row+1][column-1]!=9)
		area[row+1][column-1]+=1;
}

void printArea(int row, int column){
    printf("\n");
    for(int i=0; i<row; printf("\n"), i++)
        for(int j=0; j<column; j++)
            printf("%2d ", area[i][j]);
    printf("\n");
}

void printMines(int row, int column){
    printf("\n");
    for(int i=0; i<row; printf("\n"), i++){
        for(int j=0; j<column; j++){
            if(area[i][j]==9)
                printf("%2c ", '*');
            else
                printf("%2c ", userArea[i][j]);
        }
    }
    printf("\n");
}

void printUserArea(int row, int column){
    printf("\n");
    for(int i=0; i<row; printf("\n"), i++)
        for(int j=0; j<column; j++)
            printf("%2c ", userArea[i][j]);
    printf("\n");
}

void initialize(int row, int column, int mines){
    int row1, column1;
    for(int i=0; i<mines;){
        row1=rand()%row;
        column1=rand()%column;
        if(area[row1][column1]!=9){
            area[row1][column1]=9;
            addSum(row1, column1, row, column);
            i++;
        }
    }
    for(int i=0; i<row; i++)
        for(int j=0; j<column; j++)
            userArea[i][j]='X';
}

void reveal(int row, int column, int r, int c){
    if(area[row][column] == 0){
        userArea[row][column]='-';
        visited[row][column]=1;
    }else if(area[row][column] != 9){
        userArea[row][column]=area[row][column]+'0';
        visited[row][column]=1;
        return;
    }else
        return;
    //left
	if(column-1 >= 0 && visited[row][column-1] == 0)
        reveal(row, column-1, r, c);
    //up left
	if(column-1 >= 0 && row-1 >=0 && visited[row-1][column-1] == 0)
        reveal(row-1, column-1, r, c);
	//Up
	if(row-1 >= 0 && visited[row-1][column] == 0)
        reveal(row-1, column, r, c);
	//up right
	if(column+1 < c && row-1 >=0 && visited[row-1][column+1] == 0)
        reveal(row-1, column+1, r, c);
	//right
	if(column+1 < c && visited[row][column+1] == 0)
        reveal(row, column+1, r, c);
	//down right
	if(column+1 < c && row+1 < r && visited[row+1][column+1] == 0)
        reveal(row+1, column+1, r, c);
	//down
	if(row+1 < r && visited[row+1][column] == 0)
        reveal(row+1, column, r, c);
	//down left
    if(column-1 >= 0 && row+1 < r && visited[row+1][column-1] == 0)
        reveal(row+1, column-1, r, c);
}



int main(){
    int row, column, choice, found=0, M, N, mines;
    printf("Area Dimension: row x column: ");
    scanf("%d %d", &M, &N);
    area=(int**)calloc(M, sizeof(int *));
    visited=(int**)calloc(M, sizeof(int *));
    userArea=(char**)calloc(M, sizeof(char *));
    for(int i=0; i<M; i++){
        area[i]=(int*)calloc(N, sizeof(int));
        visited[i]=(int*)calloc(N, sizeof(int));
        userArea[i]=(char*)calloc(N, sizeof(char));
    }

    printf("\nNo. Of Mines: ");
    scanf("%d", &mines);
    initialize(M, N, mines);
    printArea(M, N);
    printUserArea(M, N);
    while(1){
        printf("1.Open  2.Mark  3.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Position: ");
                scanf("%d %d", &row, &column);
                if(area[row][column]==9){
                    printMines(M, N);
                    printf("YOU LOOSE :-(\n") ;
                    exit(0);
                }
                reveal(row, column, M, N);
                printUserArea(M, N);
                break;
            case 2:
                printf("Marking Position: ");
                scanf("%d %d", &row, &column);
                userArea[row][column]='M';
                if(area[row][column]==9)
                    found++;
                printUserArea(M, N);
                break;
            case 3:
                exit(0);
        }
        if(found==mines){
            printf("YOU WON :-) !!!!\n");
            exit(0);
        }
    }
    return 0;
}
