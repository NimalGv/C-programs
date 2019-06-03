#include <stdio.h>

#define row 5
#define col 3
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

int threeTimes(int rows, int cols, char color){
	for(int i=rows; i<rows+3; i++){
		if(balloon[i][cols]!=color)
			return 0;
	}
	return 1;
}

void burst(int rows, int cols){
	for(int i=rows; i<rows+3; i++)
		balloon[i][cols]='-';
}

void findPositionAndPlace(int rows, int cols, char color){
	int column=0;
	for(int i=rows; i>=0; i--){
		if(balloon[i][cols]=='-'){
			balloon[i][cols]=color;
			if(i<=row-3 && i>=0){
				if(threeTimes(i, cols, color))
					burst(i, cols);
			}
			return;
		}
		for(int j=column; j<col; j++){
			if(balloon[i][j]=='-'){
				balloon[i][j]=color;
				if(i<=row-3 && i>=0){
					if(threeTimes(i, j, color))
						burst(i, j);
				}
				return;
			}
		}
	}
}

void placeBalloon(int rows, int cols, char color){
	int position;
	if(balloon[rows][cols]=='-'){
		balloon[rows][cols]=color;
	}else{
		findPositionAndPlace(rows, cols, color);
	}
}

int main(void) {
	int colNo, choice;
	char color;

	initialize();
	printBalloon();
	do{
		printf("\nEnter Column No: ");
		scanf("%d", &colNo);
		printf("\nEnter Color: ");
		scanf("\n%c", &color);
		placeBalloon(placeRow, colNo-1, color);
		printBalloon();
		printf("Do you wish to continue? 1/0 : ");
		scanf("%d", &choice);
	}while(choice);
	return 0;
}
