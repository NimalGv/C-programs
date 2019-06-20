#include <stdio.h>
#include <malloc.h>

#define vertices 5
#define edge 7

typedef struct node{
	char vertex;
	struct node *next;
}NODE;


typedef struct header{
	struct header *next;
	NODE *start;
}HEADER;

HEADER *headstart;

typedef struct data{
	char vertex1;
	char vertex2;
	int weight;
}EDGE;

void initialize(){
	for(int i=0; i<vertices; i++){
		HEADER *newhead, *point;
		newhead=(HEADER*)malloc(sizeof(HEADER));
		newhead->next=NULL;

		NODE *newnode;
		newnode=(NODE*)malloc(sizeof(NODE));
		newnode->vertex='A'+i;
		newnode->next=NULL;

		newhead->start=newnode;
		if(!headstart)
			headstart=newhead;
		else{
			for(point=headstart; point->next; point=point->next);
			point->next=newhead;
		}

	}
}

void connect(char vertex1, char vertex2, int weight){
	HEADER *headA, *headB, *headpoint, *prevhead;
	NODE *nodeA, *nodeB, *nodepoint;
	int found=0;

	for( headpoint=headstart; headpoint && found!=1; prevhead=headpoint, headpoint=headpoint->next){
		for(nodepoint=headpoint->start; nodepoint; nodepoint=nodepoint->next){
			if(nodepoint->vertex==vertex1){
				found=1;
				break;
			}
		}
	}
	nodeA=nodepoint;
	headA=prevhead;

	//printf("1:%c\t", nodeA->vertex);
	//printf("2:%c\n", headA->start->vertex);

	found=0;


	for( headpoint=headstart; headpoint && found!=1; prevhead=headpoint, headpoint=headpoint->next){
		for(nodepoint=headpoint->start; nodepoint; nodepoint=nodepoint->next){
			if(nodepoint->vertex==vertex2){
				found=1;
				break;
			}
		}
	}
	nodeB=nodepoint;
	headB=prevhead;

	//printf("1:%c\t", nodeB->vertex);
	//printf("2:%c\n", headB->start->vertex);



	if(headA!=headB){

		for(nodepoint=headA->start; nodepoint->next; nodepoint=nodepoint->next);
			nodepoint->next=headB->start;

		for(headpoint=headstart; headpoint->next!=headB; headpoint=headpoint->next);
		headpoint->next=headB->next;
		free(headB);
	}


}

void display(){
	//printing
	for(HEADER *headpoint=headstart; headpoint; printf("\n"), headpoint=headpoint->next)
		for(NODE *nodepoint=headpoint->start; nodepoint; printf("%c ", nodepoint->vertex), nodepoint=nodepoint->next);

}

EDGE edges[]={{'C','D',1},
			  {'B','C',2},
			  {'B','E',2},
			  {'A','C',3},
			  {'C','E',4},
			  {'A','B',5},
			  {'D','E',6} };

/*EDGE edges[]={
			 {'B', 'C', 6},
			 {'A', 'D', 10},
			 {'D', 'C', 15},
			 {'A', 'C', 20},
			 {'D', 'E', 25}};    */

int main(){
	initialize();
	for(int i=0; i<edge; i++)
		connect(edges[i].vertex1, edges[i].vertex2, edges[i].weight);
	display();
	return 0;
}


