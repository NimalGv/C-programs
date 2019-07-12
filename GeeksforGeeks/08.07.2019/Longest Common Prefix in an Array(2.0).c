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
int first=1;

void addToList(char letter, int position){
	LIST *point, *previous;
	int placed=0;
	if(first){
		LIST *newNode;
		newNode=(LIST*)calloc(1, sizeof(LIST));
		newNode->letter=letter;
		newNode->position=position;
		newNode->count=0;
		newNode->next=NULL;
		if(!start)
			start=newNode;
		else{
			for(point=start; point->next; point=point->next);
			point->next=newNode;
		}
	}
	for(point=start; point; previous=point, point=point->next){
		if(point->letter==letter && point->position==position){
			point->count++;
			break;
		}
	}
}

void removeList(int size){
	LIST *point, *previous;
	for(point=start; point && point->count==size; previous=point, point=point->next);
	previous->next=NULL;
}

void printList(int size){
	int printed=0;
//	for(LIST* point=start; point; point=point->next)
//		printf("%c %d %d \n", point->letter, point->position, point->count);
	for(LIST* point=start; point; point=point->next){
		printf("%c", point->letter);
		printed=1;
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
			if(i==0)
				first=0;
			else
				removeList(i+1);
		}
		printList(size);
		free(string);
		start=NULL;
		first=1;
		printf("\n");
      }

	return 0;
}
