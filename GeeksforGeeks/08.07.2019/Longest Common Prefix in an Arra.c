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

//char stringArray[][15]={"geeks", "geeksforgeeks", "geek", "geezer"};
char stringArray[][15]={"apple", "aple",  "april"};

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
		newNode=(LIST*)malloc(sizeof(LIST));
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

void printList(){
	int printed=0;
//	for(LIST* point=start; point; point=point->next)
//		printf("%c %d %d \n", point->letter, point->position, point->count);
	for(LIST* point=start; point; point=point->next){
		if(point->count==3-1){
			printf("%c", point->letter);
			printed=1;
		}else
			break;
	}
	if(!printed)
		printf("-1");
}

int main(){

	for(int i=0; i<3; i++){
		for(int j=0; j<strlen(stringArray[i]); j++)
			addToList(stringArray[i][j], j);
	}
	printList();

	return 0;
}
