#include <stdio.h>

#define row 5
#define col 5
void place(int rows, int column, char color);

int balloon[row][col];
int placeRow=row-1;

void initialize(){
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			balloon[i][j]='-';

}

void printBalloon(){
	printf("\n");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++)
			printf("%c ", balloon[i][j]);
		printf("\n");
	}

}

int freeAbovePos(int r, int c){
	int pos;
	if(r<0)
		return r;
	if(balloon[r][c]!='-'){
		pos=freeAbovePos(r-1, c);
	}else{
		return r;
	}
	return pos;
}

int findPos(int rows, int cols, char color){
	int i=0;
	for(i=0; i<col; i++){
		if(balloon[rows][i]!='-'){
			continue;
		}else{
			return i;
		}
	}
	place(rows-1, cols, color);
	placeRow--;
}


void place(int rows, int column, char color){
	//printf("\n%d %d %c", placeRow, column, color);
	/*if(freeAbovePos(placeRow, column)>=0)
		ballon[freeAbovePos(placeRow, column)][column]=color;
	else
		printf("Can't Fill!\n");	*/
	if(balloon[rows][column]!='-'){
		balloon[rows][findPos(rows, column, color)]=color;
	}
	else{
		balloon[rows][column]=color;
	}

}


int main(void) {
	int colNo, choice;
	char color;

	initialize();
	printBalloon();
	do{
		/*ballon[4][2]='R';
		ballon[3][2]='R';
		ballon[2][2]='R';*/
		printf("\nEnter Column No: ");
		scanf("%d", &colNo);
		printf("\nEnter Color: ");
		scanf("\n%c", &color);
		place(placeRow, colNo-1, color);
		printBalloon();
		printf("Do you wish to continue? 1/0 : ");
		scanf("%d", &choice);
	}while(choice);
	return 0;
}
