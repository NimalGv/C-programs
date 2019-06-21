#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

/*EDGE edges[]={
			 {'A', 'B', 6},
			 {'A', 'D', 1},
			 {'D', 'E', 1},
			 {'B', 'C', 5},
			 {'B', 'E', 2},
			 {'D', 'B', 2},
			 {'E', 'C', 5}}; */

EDGE edges[]={
			 {'A', 'C', 20},
			 {'A', 'D', 10},
			 {'D', 'C', 15},
			 {'B', 'C', 6},
			 {'D', 'E', 25}};

typedef struct dijkstraTable{
    int cost;
    int visited;
    char previousVertex;
}DIJKSTRA;

DIJKSTRA table[vertices];


void initialize(){
    for(int i=0; i<vertices; i++){
        table[i].cost=INT_MAX;
        table[i].visited=0;
        table[i].previousVertex=NULL;
    }
}

void displayTable(){
    printf("\n\n");
    printf("       COST  VISITED  PREVIOUS\n");
    for(int i=0; i<vertices; i++)
        printf("%c\t%d\t%d\t%c\n", i+'A', table[i].cost, table[i].visited, table[i].previousVertex);
}

char minimumCost(){
    int minimum=INT_MAX;
    char vertex=NULL;

    for(int i=0; i<vertices; i++){
        if((minimum > table[i].cost) && (table[i].visited!=1)){
            minimum=table[i].cost;
            vertex=i+'A';
        }
    }
    return vertex;
}

void dijkstraAlgorithm(char start){
    NODE *point;
    table[start-'A'].cost=0;
    while(1){
        char minimum=minimumCost();
        if(minimum==NULL)
            return;
        //printf("%c", minimum);
        table[minimum-'A'].visited=1;
        for(point=Header[minimum-'A']; point; point=point->nxt){
            if(table[point->vertex-'A'].visited!=1){
                if((table[minimum-'A'].cost+point->weight) < table[point->vertex-'A'].cost){
                    table[point->vertex-'A'].cost=table[minimum-'A'].cost+point->weight;
                    table[point->vertex-'A'].previousVertex=minimum;
                }
            }
        }
        displayTable();
    }
}


void insert(char vertex1, char vertex2, int weight){
    NODE *newnode, *point, *prev;
    newnode =(NODE*)malloc(sizeof(NODE));
    newnode->vertex=vertex2;
    newnode->weight=weight;
    newnode->nxt=NULL;

    if(Header[vertex1-'A']==NULL)
        Header[vertex1-'A']=newnode;
    else{
        for(point=prev=Header[vertex1-'A']; point; prev=point, point=point->nxt){
            if(weight < point->weight)
                break;
        }
        if(point==Header[vertex1-'A']){
            newnode->nxt=point;
            Header[vertex1-'A']=newnode;
        }else{
            newnode->nxt=point;
            prev->nxt=newnode;
        }
    }
}

void display(){
    printf("\n");
    for(int i=0; i<vertices; printf("\n"), i++)
        for(NODE* j=Header[i]; j; printf("%c(%d) ", j->vertex, j->weight), j=j->nxt);
}

int main(){

    for(int i=0; i<edge; i++){
        insert(edges[i].vertex1, edges[i].vertex2, edges[i].weight);
        insert(edges[i].vertex2, edges[i].vertex1, edges[i].weight);
    }

    display();
    initialize();
    dijkstraAlgorithm('A');


    return 0;
}
