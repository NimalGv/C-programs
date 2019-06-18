#include <stdio.h>
#include <stdlib.h>

#define vertices 5
#define edge 5

typedef struct data{
	char vertex1;
	char vertex2;
	int weight;
}EDGE;

typedef struct order{
    char vertex;
    struct order *next;
}ORDER;

ORDER *orderStart;

typedef struct queue{
    char vertex;
    struct queue *next;
}QUEUE;

QUEUE *queueHead, *queueTail;

EDGE edges[]={{'A', 'C', 20},{'A', 'D', 10},{'D', 'C', 15},
				{'B', 'C', 6},{'D', 'E', 25}};

int matrix[vertices][vertices];

void insertIntoOrder(char vertex){
    ORDER *newnode, *tptr;
    newnode=(ORDER*)malloc(sizeof(ORDER));
    newnode->vertex=vertex;
    newnode->next=NULL;

    if(!orderStart)
        orderStart=newnode;
    else{
        for(tptr=orderStart; tptr->next; tptr=tptr->next);
        tptr->next=newnode;
    }
}

void enqueue(char vertex){
    QUEUE *newnode;
    newnode=(QUEUE*)malloc(sizeof(QUEUE));
    newnode->vertex=vertex;
    newnode->next=NULL;

    if(!queueHead){
        queueHead=queueTail=newnode;
    }
    else{
        queueTail->next=newnode;
        queueTail=newnode;
    }
}

char dequeue(){
    QUEUE *element;
    element=queueHead;
    queueHead=queueHead->next;
    return element->vertex;
}

int foundInOrder(char vertex){
    ORDER *point;
    for(point=orderStart; point; point=point->next){
        if(point->vertex==vertex)
            return 1;
    }
    return 0;
}

int empty(){
    if(queueHead==NULL)
        return 0;
    return 1;
}


void BFS(char vertex){
   QUEUE *tptr;
   ORDER *point;
   int run=0;
   enqueue(vertex);
   while(empty()){
       vertex=dequeue();
       if(!foundInOrder(vertex)){
           insertIntoOrder(vertex);
           for(int i=0; i<vertices; i++){
             if(matrix[vertex-'A'][i]!=0)
                if(!foundInOrder(i+'A'))
                    enqueue(i+'A');
           }
       }
   }
   for(point=orderStart; point; printf("%c ", point->vertex),point=point->next);
}


int main(){
    QUEUE *tptr;

    //creating a adjacency matrix

	for(int i=0; i<vertices; i++){
		for(int j=0; j<vertices; j++){
			matrix[edges[i].vertex1-'A'][edges[i].vertex2-'A']=edges[i].weight;
			matrix[edges[i].vertex2-'A'][edges[i].vertex1-'A']=edges[i].weight;
		}
	}

	//displaying

	printf("  ");
	for(int i=0; i<vertices; printf("  %c", 'A'+i), i++);
	printf("\n\n");
	for(int i=0; i<vertices; printf("\n"), i++){
		printf("%c  ", 'A'+i);
		for(int j=0; j<vertices; printf("%2d ", matrix[i][j++]));
	}

	printf("\n\n\n");

	//BFS
	BFS('E');




  	return 0;
}
