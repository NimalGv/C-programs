#include<stdio.h>
#include<malloc.h>

struct node{
	int data;
	struct node *nxt;
};
typedef struct node node;

struct seqlist{
	node* point;
};
typedef struct seqlist seqlist;

node* create(int value){
	node* newnode;
	newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->nxt=NULL;
	return newnode;
}

int main(){
	node *temp, *prev;
	int n, q;
	scanf("%d %d", &n, &q);
	seqlist seq[n];
	for(int i=0; i<n; seq[i].point=NULL, i++);
	
	for(int i=0; i<q; i++){
		scanf("%d %d %d", &tq, &x, &y)
		pos=()
		if(tq==1){
			if(seq[pos].point==NULL){
				seq[pos].point=create(1);
			}else{
				for(temp=seq[pos].point; temp!=NULL; prev=temp, temp=temp->nxt);
				prev->nxt=create(34);
			}
		}
		
	}
	
	
	
	//printf("%d ", prev->data);
	
	for(temp=seq[0].point; temp!=NULL; printf("%d ", temp->data), temp=temp->nxt);
}
