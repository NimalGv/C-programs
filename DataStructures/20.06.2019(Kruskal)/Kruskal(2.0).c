#include <stdio.h>
#include <malloc.h>
#include <conio.h>

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

void display(){
	//printing
	for(HEADER *headpoint=headstart; headpoint; printf("\n"), headpoint=headpoint->next)
		for(NODE *nodepoint=headpoint->start; nodepoint; printf("%c ", nodepoint->vertex), nodepoint=nodepoint->next);

}

HEADER* findHead(char vertex){
	HEADER *headpoint, *prevhead;
	NODE *nodepoint;
	int found=0;
	for( headpoint=headstart; headpoint && found!=1; prevhead=headpoint, headpoint=headpoint->next){
		for(nodepoint=headpoint->start; nodepoint; nodepoint=nodepoint->next){
			if(nodepoint->vertex==vertex){
				found=1;
				break;
			}
		}
	}
	return prevhead;
}

void connect(char vertex1, char vertex2, int weight){
	HEADER *headA, *headB, *headpoint;
	NODE *nodepoint;

	headA=findHead(vertex1);
	headB=findHead(vertex2);



	if(headA!=headB){
		for(nodepoint=headA->start; nodepoint->next; nodepoint=nodepoint->next);
			nodepoint->next=headB->start;

		if(headB==headstart){
			headstart=headB->next;
		}else{
			for(headpoint=headstart; headpoint->next!=headB; headpoint=headpoint->next);
			headpoint->next=headB->next;
			free(headB);
		}
	}

	display();
	printf("\n\n");
	getch();


}



/*EDGE edges[]={
			 {'B', 'C', 6},
			 {'A', 'D', 10},
			 {'D', 'C', 15},
			 {'A', 'C', 20},
			 {'D', 'E', 25}};*/

EDGE edges[]={{'C','D',1},
			  {'B','C',2},
			  {'B','E',2},
			  {'A','C',3},
			  {'C','E',4},
			  {'A','B',5},
			  {'D','E',6} };

int main(){
	initialize();
	for(int i=0; i<edge; i++)
		connect(edges[i].vertex1, edges[i].vertex2, edges[i].weight);
	display();
	return 0;
}


