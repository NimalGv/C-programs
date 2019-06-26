#include <stdio.h>
#include <stdlib.h>

int array[]={12, 1, 3, 4, 6, 0};

typedef struct node{
    int data;
    struct node *next;
}NODE;

typedef struct list{
    NODE *start;
    NODE *end;
}LIST;

LIST header[64];

void copy(){
    int i;
    LIST *point;
    NODE *newnode;
    for(i=1; header[i].start; i++);
    for(int j=0; j!=i; j++){
        for(NODE *nodePoint=header[j].start; nodePoint; nodePoint=nodePoint->next){
            newnode=(NODE*)malloc(sizeof(NODE));
            newnode->data=nodePoint->data;
            newnode->next=NULL;
            if(header[i+j].start==NULL)
                header[i+j].start=header[i+j].end=newnode;
            else{
                header[i+j].end->next=newnode;
                header[i+j].end=newnode;
            }
        }
    }
}

void addNumber(int number, int position){
    int times=position;
    NODE *newNode;
    for(int i=position, j=0; j<times; i++, j++){
        newNode=(NODE*)malloc(sizeof(NODE));
        newNode->data=number;
        newNode->next=NULL;
        if(header[i].start==NULL){
            header[i].start=newNode;
            header[i].end=newNode;
        }else{
            header[i].end->next=newNode;
            header[i].end=newNode;
        }
    }

}

void print(){
    printf("\n");
    for(int i=0; i<64; printf("\n"), i++)
        for(NODE *point=header[i].start; point; printf("%d->", point->data), point=point->next);
    printf("\n");
}

int power(int number){
    int product=1;
    for(int i=0; i<number; product*=2, i++);
    return product;
}

int main(){
    //addNumber();
    //printf("%d", power(2));
    for(int i=0; i<6; i++){
        copy();
        addNumber(array[i], power(i));
    }
    print();
    return 0;
}
