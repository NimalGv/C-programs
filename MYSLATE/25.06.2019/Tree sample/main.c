#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int start, end, mid, data;
    struct tree *left;
    struct tree *right;
}TREE;

TREE *root;

int array[]={10, 7, 2, 5, 6, 4, 12, 3, 1, 8};

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
    if(start==end)
        newnode->data=array[start];
    else
        newnode->data=newnode->left->data+newnode->right->data;

    return newnode;
}

int fetchTotalDistance(int start, int end, TREE *node){
    int sum=0;
    int sum1, sum2;

    if(start <= node->start && end >= node->end)
        return node->data;
    else if((node->end < start && node->start < end) || (node->start > end && node->end > start))
        return 0;
    else{
        sum1=fetchTotalDistance(start, end, node->left);
        sum2=fetchTotalDistance(start, end, node->right);
        sum+=(sum1+sum2);
        return sum;
    }
}

void delayOnStation(int station, int delay, int mid, TREE *node){
    if(station==node->start && station==node->end){
        node->data+=delay;
        return;
    }
    if(station <= node->mid){
        delayOnStation(station, delay, node->mid, node->left);
        node->data+=delay;
    }
    if(station > node->mid){
        delayOnStation(station, delay, node->mid, node->right);
        node->data+=delay;
    }
}

void print(TREE *node){
    if(node){
        print(node->left);
        print(node->right);
        printf("(%d , %d):(%d)\n", node->start, node->end, node->data);
    }
}

int main(){
    root=create(0, 9);
    print(root);
    printf("\nTotal Distance: %d\n", fetchTotalDistance(3, 7, root));
    delayOnStation(2, 5, 0, root);
    print(root);
    printf("\nTotal Distance: %d\n", fetchTotalDistance(3, 7, root));
    return 0;
}
