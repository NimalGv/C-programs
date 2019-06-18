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


int main(){
    char vertex1, vertex2;
    int  weight, choice;
    printf("1. Insert()  2. Display() 3. Exit\n");
    while(1){
        scanf("%d", &choice);
        switch(choice){
            case 1:
                scanf("\n%c %c %d", &vertex1, &vertex2, &weight);
                insert(vertex1, vertex2, weight);
                insert(vertex2, vertex1, weight);
                break;

            case 2:
                display();
                break;

            case 3:
                exit(0);

        }
    }


}
