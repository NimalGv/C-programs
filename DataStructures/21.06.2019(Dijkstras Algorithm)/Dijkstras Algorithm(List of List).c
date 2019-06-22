#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define vertices 5
#define edge 7

typedef struct data{
	char vertex1;
	char vertex2;
	int weight;
}EDGE;

EDGE edges[]={
			 {'A', 'B', 6},
			 {'A', 'D', 1},
			 {'D', 'E', 1},
			 {'B', 'C', 5},
			 {'B', 'E', 2},
			 {'D', 'B', 2},
			 {'E', 'C', 5}};


typedef struct node{
    char vertex;
    int weight;
    struct node *nxt;
}NODE;


typedef struct head{
    char index;
    struct head *nxt;
    NODE *start;
}HEAD;

HEAD *begin;

typedef struct dijkstraTable{
    char vertex;
    int cost;
    int visited;
    char previousVertex;
    struct dijkstraTable *next;
}DIJKSTRA;

DIJKSTRA *tableStart;

void displayTable(){
    printf("\n\n");
    for(DIJKSTRA *point=tableStart; point; point=point->next)
        printf("%c %d %d %c\n", point->vertex, point->cost, point->visited, point->previousVertex);
}

void initialize(char vertex){
    DIJKSTRA *newtable, *point, *prev;
    newtable=(DIJKSTRA*)malloc(sizeof(DIJKSTRA));
    newtable->vertex=vertex;
    newtable->cost=INT_MAX;
    newtable->visited=0;
    newtable->previousVertex=NULL;
    newtable->next=NULL;

    if(!tableStart)
        tableStart=newtable;
    else{
        for(prev=point=tableStart; point; prev=point, point=point->next){
            if(vertex < point->vertex)
                break;
        }
        if(point==tableStart){
            newtable->next=tableStart;
            tableStart=newtable;
        }else{
            newtable->next=point;
            prev->next=newtable;
        }
    }
}

char minimumCost(){
    int minimum=INT_MAX;
    char vertex=NULL;
    DIJKSTRA *pointTable;

    for(pointTable=tableStart; pointTable->next; pointTable=pointTable->next){
        if((minimum > pointTable->cost) && (pointTable->visited!=1)){
            minimum=pointTable->cost;
            vertex=pointTable->vertex;
        }
    }
    return vertex;
}

void setCost(char vertex, int value){
    DIJKSTRA *pointTable;
    for(pointTable=tableStart; pointTable->next; pointTable=pointTable->next){
            if(pointTable->vertex == vertex){
                pointTable->cost=value;
                break;
            }
    }
}

void setVisited(char vertex, int value){
    DIJKSTRA *pointTable;
    for(pointTable=tableStart; pointTable->next; pointTable=pointTable->next){
            if(pointTable->vertex == vertex){
                pointTable->visited=value;
                break;
            }
    }
}

int getCost(char vertex){
    DIJKSTRA *pointTable;
    for(pointTable=tableStart; pointTable->next; pointTable=pointTable->next){
            if(pointTable->vertex == vertex){
                return pointTable->cost;
            }
    }
}

void setPreviousVertex(char vertex, char previousVertex){
    DIJKSTRA *pointTable;
    for(pointTable=tableStart; pointTable->next; pointTable=pointTable->next){
            if(pointTable->vertex == vertex){
                pointTable->previousVertex=previousVertex;
                break;
            }
    }
}

int isVisited(char vertex){
    DIJKSTRA *pointTable;
    for(pointTable=tableStart; pointTable->next; pointTable=pointTable->next){
            if(pointTable->vertex == vertex){
                if(pointTable->visited==1)
                    return 1;
            }
    }
    return 0;
}

void dijkstraAlgorithm(char start){
    NODE *point;
    HEAD *pointHead;
    DIJKSTRA *pointTable;
    int previous;
    setCost(start, 0);
    while(1){
        char minimum=minimumCost();
        if(minimum==NULL)
            return;
        setVisited(minimum, 1);

        for(pointHead=begin; pointHead && pointHead->index!=minimum; pointHead=pointHead->nxt);

        for(point=pointHead->start; point; point=point->nxt){
            if(!isVisited(point->vertex)){
                previous=getCost(minimum)+point->weight;
                if(previous < getCost(point->vertex)){
                    setCost(point->vertex, previous);
                    setPreviousVertex(point->vertex, minimum);
                }
            }
        }
        displayTable();
    }
}


void insert(char vertex1, char vertex2, int weight){
    //printf("*");
    NODE *newnode, *nodepoint, *nodeprev;
    HEAD *point, *prev;
    int found=0;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->vertex=vertex2;
    newnode->weight=weight;
    newnode->nxt=NULL;

    if(!begin){
        HEAD *newhead;
        newhead=(HEAD*)malloc(sizeof(HEAD));
        newhead->index=vertex1;
        newhead->start=newnode;
        newhead->nxt=NULL;
        begin=newhead;
        initialize(vertex1);
    }else{
        for(point=begin; point->nxt; point=point->nxt){
            if(point->index==vertex1){
                found=1;
                break;
            }
        }
        if(point->index==vertex1){
            found=1;
        }
        if(found){
            for(nodepoint=nodeprev=point->start; nodepoint; nodeprev=nodepoint, nodepoint=nodepoint->nxt)
            if(newnode->weight < nodepoint->weight)
                break;
            if(point->start==nodepoint){
                newnode->nxt=nodepoint;
                point->start=newnode;
            }else{
                newnode->nxt=nodepoint;
                nodeprev->nxt=newnode;
            }
        }else{
            HEAD *newhead;
            newhead=(HEAD*)malloc(sizeof(HEAD));
            newhead->index=vertex1;
            newhead->start=newnode;
            for(point=prev=begin; point; prev=point, point=point->nxt)
            if(newhead->index < point->index)
                break;
            newhead->nxt=point;
            prev->nxt=newhead;
            initialize(vertex1);
        }
    }

}

void display(){
    HEAD *i;
    NODE *j;
    printf("\n");
    printf("\t\tADJACENCY LIST\n");
    for(i=begin; i; printf("\n"), i=i->nxt){
        printf("%c  ", i->index);
        for(j=i->start; j; j=j->nxt)
            printf("%c(%d) ", j->vertex, j->weight);
    }
    printf("\n");
}


int main(){
    char vertex1, vertex2;
    int  weight, choice;
    for(int i=0; i<edge; i++){
        insert(edges[i].vertex1, edges[i].vertex2, edges[i].weight);
        insert(edges[i].vertex2, edges[i].vertex1, edges[i].weight);
    }
    display();
    displayTable();
    dijkstraAlgorithm('A');
    displayTable();

    return 0;
}
