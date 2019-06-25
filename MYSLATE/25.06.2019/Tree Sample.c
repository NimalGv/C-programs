#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int start, end, mid;
    struct tree *left;
    struct tree *right;
}TREE;

TREE *root;



TREE* create(int start, int end){
    TREE *newnode;
    newnode=(TREE*)malloc(sizeof(TREE));
    newnode->start=start;
    newnode->end=end;
    newnode->mid=(start+end)/2;
    newnode->left=NULL;
    newnode->right=NULL;
    if(!root)
        root=newnode;
    if(start!=end){
        newnode->left=create(newnode->start, newnode->mid);
        newnode->right=create(newnode->mid+1, newnode->end);
    }
    return newnode;
}

void print(TREE *node){
    if(node){
        print(node->left);
        print(node->right);
        printf("(%d , %d)\n", node->left, node->right);
    }
}

int main(){
    root=create(0, 1);
    print(root);
    return 0;
}
