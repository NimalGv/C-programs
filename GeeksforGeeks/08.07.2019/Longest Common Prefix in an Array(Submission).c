#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
	char letter;
	int position;
	int count;
	struct list *next;
}LIST;
LIST *start;

void addToList(char letter, int position){
	LIST *point, *previous;
	int placed=0;
	for(point=start; point; previous=point, point=point->next){
		if(point->letter==letter && point->position==position){
			point->count++;
			placed=1;
			break;
		}
		if(position < point->position)
			placed=1;
	}
	if(!placed){
		LIST *newNode;
		newNode=(LIST*)calloc(1, sizeof(LIST));
		newNode->letter=letter;
		newNode->position=position;
		newNode->count=0;
		newNode->next=NULL;
		if(!start)
			start=newNode;
		else
			previous->next=newNode;
	}
}

void printList(int size){
	int printed=0;
	for(LIST* point=start; point; point=point->next){
		if(point->count==size-1){
			printf("%c", point->letter);
			printed=1;
		}else
			break;
	}
	if(!printed)
		printf("-1");
}

int main(){
      int testCase, size;
      char *string;
      scanf("%d", &testCase);
      while(testCase--){
		scanf("%d", &size);
		for(int i=0; i<size; i++){
			string=(char*)calloc(100, sizeof(char));
			scanf("%s", string);
			for(int j=0; string[j]; j++)
				addToList(string[j], j);
		}
		printList(size);
		free(string);
		start=NULL;
		printf("\n");
      }

	return 0;
}
