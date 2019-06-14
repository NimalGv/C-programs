#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *nxt;
};
typedef struct node node;
node *head=NULL;
int size=0;

node* create(int data){
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->nxt=NULL;
	return newnode;
}

node* insertfirst(node *head, int data){
    node *temp, *nn;
    if(head==NULL){
        head=create(data);
        size++;
        return head;
    }else{
        nn=create(data);
        nn->nxt=head;
        head=nn;
        size++;
        return head;
    }
}

node* insertlast(node *head, int data){
    node *temp;
    for(temp=head; temp->nxt; temp=temp->nxt);
    temp->nxt=create(data);
    return head;
}

node* insertpos(node *head, int pos, int data){
    node *temp, *prev, *nn;
    int i=1;
    for(temp=head; i!=pos; prev=temp, temp=temp->nxt, i++);
    nn=create(data);
    nn->nxt=temp;
    prev->nxt=nn;
    return head;
}

node* del(node *head, int pos){
    node *i, *prev, *temp;
    if(pos==1){
        temp=head;
        head=head->nxt;
        free(temp);
        return head;
    }
    int j=1;
    for(i=head; j!=pos; prev=i, i=i->nxt, j++);
    prev->nxt=i->nxt;
    free(i);
    return head;


}

void display(node *head){
    node *temp;
    printf("Linked List: ");
    for(temp=head; temp; temp=temp->nxt)
        printf("%d ", temp->data);
    printf("\n");
}

int main(){
    int choice, data, position;
    printf("1.Insert First 2.Insert last 3.Insert at position 4.Display 5.Delete\n");
    while(1){
        scanf("%d", &choice);
        switch(choice){
            case 1: scanf("%d", &data);
                    head=insertfirst(head, data);
                    break;
            case 2: scanf("%d", &data);
                    head=insertlast(head, data);
                    break;
            case 3: scanf("%d %d", &data, &position);
                    head=insertpos(head, position, data);
                    break;
            case 4: display(head);
                    break;
            case 5: scanf("%d", &position);
                    head=del(head, position);
                    break;
            default: exit(0);
        }
    }


    return 0;
}
