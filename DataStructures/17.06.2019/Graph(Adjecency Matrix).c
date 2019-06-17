#include <stdio.h>

#define vertices 5
#define edge 5

typedef struct data{
	char vertex1;
	char vertex2;
	int weight;
}EDGE;

EDGE edges[]={{'A', 'C', 20},{'A', 'D', 10},{'D', 'C', 15},
				{'B', 'C', 6},{'D', 'E', 25}};

int matrix[vertices][vertices];

int main(){
	for(int i=0; i<vertices; i++){
		for(int j=0; j<vertices; j++){
			matrix[edges[i].vertex1-'A'][edges[i].vertex2-'A']=edges[i].weight;
			matrix[edges[i].vertex2-'A'][edges[i].vertex1-'A']=edges[i].weight;
		}
	}

	printf("  ");
	for(int i=0; i<vertices; printf("  %c", 'A'+i), i++);
	printf("\n\n");
	for(int i=0; i<vertices; printf("\n"), i++){
		printf("%c  ", 'A'+i);
		for(int j=0; j<vertices; printf("%2d ", matrix[i][j++]));
	}


  	return 0;
}
