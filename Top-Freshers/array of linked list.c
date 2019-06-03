#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nxt;
};
typedef struct node node;

struct array{
    node *point;
};
typedef struct array array;

node* create(int data){
    node* nnode;
    nnode=(node*)malloc(sizeof(node));
    nnode->data=data;
    nnode->nxt=NULL;
    return nnode;
}

int main(){
    array *A;
    node *temp, *prev;
    int size1, size2, data;
    printf("Size of array: ");
    scanf("%d", &size1);
    A=(array*)malloc(size1*sizeof(array));

    for(int i=0; i<size1; i++)
        A[i].point=NULL;

    for(int i=0; i<size1; i++){
        printf("\nEnter A[%d] size: ", i);
        scanf("%d", &size2);
        for(int j=0; j<size2; j++){
            printf("\nEnter Data: ");
            scanf("%d", &data);
            if(A[i].point==NULL)
                A[i].point=create(data);
            else{
                for(temp=A[i].point; temp!=NULL; prev=temp, temp=temp->nxt);
                prev->nxt=create(data);
            }
        }
    }

    printf("\n\nDisplaying..........\n");

    for(int i=0; i<size1; i++){
        for(temp=A[i].point; temp!=NULL; temp=temp->nxt)
            printf("%d ", temp->data);
        printf("\n");

    }

    return 0;
}
