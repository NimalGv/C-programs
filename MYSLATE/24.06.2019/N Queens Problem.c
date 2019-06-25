#include <stdio.h>
#include <stdlib.h>

#define size 8

static int found=0;

char chessBoard[size][size];

void initialize(){
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
			chessBoard[i][j]='-';
}

void printBoard(){
	printf("\n");
	for(int i=0; i<size; printf("\n"), i++)
		for(int j=0; j<size; printf("%c ", chessBoard[i][j]), j++);
	printf("\n");
}

int isSafe(int row, int column){
	//left
	for(int c=column; c-1 >= 0; c--)
		if(chessBoard[row][c-1]=='Q')
			return 0;
    //up left
	for(int c=column, r=row; c-1 >= 0 && r-1 >= 0; c--, r--)
		if(chessBoard[r-1][c-1]=='Q')
			return 0;
	//Up
	for(int r=row; r-1 >= 0; r--)
		if(chessBoard[r-1][column]=='Q')
			return 0;
	//up right
	for(int c=column, r=row; c+1 < size && r-1 >=0; c++, r--)
		if(chessBoard[r-1][c+1]=='Q')
			return 0;
	//right
	for(int c=column; c+1 < size; c++)
		if(chessBoard[row][c+1]=='Q')
			return 0;
	//down right
	for(int c=column, r=row; c+1 < size && r+1 < size; c++, r++)
		if(chessBoard[r+1][c+1]=='Q')
			return 0;
	//down
	for(int r=row; r+1 < size; r++)
		if(chessBoard[r+1][column]=='Q')
			return 0;
	//down left
	for(int r=row, c=column; c-1 >= 0 && r+1 < size; c--, r++)
		if(chessBoard[r+1][c-1]=='Q')
			return 0;
	return 1;
}

void placeQueen(int row){
	int col;
	for(col=0; col < size && row < size && !found; col++){
		if(isSafe(row, col)){
			chessBoard[row][col]='Q';
			placeQueen(row+1);
			if(!found)
				chessBoard[row][col]='-';
		}
	}
	//printBoard();
	if(row==size)
		found=1;
}

int main(void) {
  initialize();
  printBoard();
  placeQueen(0);
  printBoard();
  return 0;
}
