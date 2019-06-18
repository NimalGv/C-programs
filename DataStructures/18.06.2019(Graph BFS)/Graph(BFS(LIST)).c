#include <stdio.h>
#include <stdlib.h>


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
   HEAD *headPoint;
   NODE *nodePoint;

   printf("BFS:\t");
   enqueue(vertex);
   while(empty()){
       vertex=dequeue();
       if(!foundInOrder(vertex)){
           insertIntoOrder(vertex);
           /*for(int i=0; i<vertices; i++){
             if(matrix[vertex-'A'][i]!=0)
                if(!foundInOrder(i+'A'))
                    enqueue(i+'A');
           } */
           for(headPoint=begin; headPoint && headPoint->index!=vertex; headPoint=headPoint->nxt);
           for(nodePoint=headPoint->start; nodePoint; nodePoint=nodePoint->nxt)
                if(!foundInOrder(nodePoint->vertex))
                    enqueue(nodePoint->vertex);

       }
   }
   for(point=orderStart; point; printf("%c ", point->vertex),point=point->next);
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
            if(newnode->vertex < nodepoint->vertex)
                break;
            newnode->nxt=nodepoint;
            nodeprev->nxt=newnode;
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

typedef struct data{
	char vertex1;
	char vertex2;
	int weight;
}EDGE;

EDGE edges[]={
			 {'A', 'C', 20},
			 {'A', 'D', 10},
			 {'D', 'C', 15},
			 {'B', 'C', 6},
			 {'D', 'E', 25}};


int main(){
    char vertex1, vertex2;
    int  weight, choice;
    for(int i=0; i<5; i++){
        insert(edges[i].vertex1, edges[i].vertex2, edges[i].weight);
        insert(edges[i].vertex2, edges[i].vertex1, edges[i].weight);
    }
    display();
    BFS('E');


}
