#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int value;
	int position;
	struct list *next;
}LIST;

LIST *start, *end;

void add(int value, int position){
	LIST *newNode;
	newNode=(LIST*)malloc(sizeof(LIST));
	newNode->value=value;
	newNode->position=position;
	newNode->next=NULL;
	if(!start)
		start=end=newNode;
	else
		end=end->next=newNode;
}

int del(){
	int value;
	value=start->value;
	if(start==end)
		start=end=NULL;
	else
		start=start->next;
	return value;
}

int listSum(){
	int sum=0;
	for(LIST *point=start; point; point=point->next)
		sum+=point->value;
	return sum;
}

int main(){
      int testCase, size, *array, found=0, gotSum=0, sum, i=0, value;
      scanf("%d", &testCase);
      while(testCase--){
		scanf("%d %d", &size, &sum);
		array=(int*)malloc(size*sizeof(int));
		for(int i=0; i<size; scanf("%d", &array[i++]));
		add(array[i], i);
		i++;
		while(start->position<size && end->position<size){
			if(listSum() < sum){
				printf("ADD: %d, SUM: %d\n", array[i], listSum());
				add(array[i], i);
				i++;
			}else if(listSum() > sum){
				value=del();
				printf("DEL: %d, SUM: %d\n", value, listSum());
			}else{
				printf("%d %d", start->position+1, end->position+1);
				found=1;
				break;
			}
		}
		if(!found)
			printf("-1");
		found=i=gotSum=0;
		start=end=NULL;
		printf("\n");
      }
	return 0;
}
