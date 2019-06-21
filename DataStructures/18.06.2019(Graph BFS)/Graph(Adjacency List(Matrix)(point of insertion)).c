#include <stdio.h>
#include <stdlib.h>

#define vertices 5
#define edge 5

typedef struct data{
	char vertex1;
	char vertex2;
	int weight;
}EDGE;

typedef struct node{
	char vertex;
	int weight;
	struct node *nxt;
}NODE;

NODE *Header[vertices];

EDGE edges[]={
			 {'A', 'C', 20},
			 {'A', 'D', 10},
			 {'D', 'C', 15},
			 {'B', 'C', 6},
			 {'D', 'E', 25}};


void insert(char vertex1, char vertex2, int weight){
	NODE *newnode, *point, *prev;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->vertex=vertex2;
	newnode->weight=weight;
	newnode->nxt=NULL;
	if(!Header[vertex1-'A']){
		Header[vertex1-'A']=newnode;
	}else{
		//newnode->nxt=Header[vertex1-'A'];
		//Header[vertex1-'A']=newnode;
		for(point=prev=Header[vertex1-'A']; point; prev=point, point=point->nxt)
            if(newnode->vertex<point->vertex)
                break;
		newnode->nxt=point;
		prev->nxt=newnode;
	}
}

int main(){

	for(int i=0; i<edge; i++){
		insert(edges[i].vertex1, edges[i].vertex2, edges[i].weight);
		insert(edges[i].vertex2, edges[i].vertex1, edges[i].weight);
	}

	printf("\t\tADJACENCY LIST\n\n");
	for(int i=0; i<vertices; printf("\n"), i++){
		printf("%c  ", 'A'+i);
		for(NODE *j=Header[i]; j; printf("%c(%d) ", j->vertex, j->weight), j=j->nxt);
	}

  	return 0;
}

