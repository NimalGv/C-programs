#include<stdio.h>
#include<stdlib.h>

struct trees{
    int data;
    struct trees *leftnode;
    struct trees *rightnode;
};
typedef struct trees trees;

trees *root=NULL;

void create(int data){
    trees *point;
    trees *newtree;
    newtree=(trees*)malloc(sizeof(trees));
    newtree->data=data;
    newtree->leftnode=newtree->rightnode=NULL;
    if(root==NULL)
        root=newtree;
    else{
        point=root;
        if(point->leftnode==NULL)
            point->leftnode=newtree;
        else if(point->rightnode==NULL)
            point->rightnode=newtree;
    }


}

int main(){
    create(5);
    printf("%d", root->data);
    create(15);
    printf("%d", root->leftnode->data);

    return 0;
}
