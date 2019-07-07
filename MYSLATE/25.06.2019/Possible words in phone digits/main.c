#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contain{
	char letter;
	struct contain *next;
}LIST;

LIST *start, *end;

int numbers[][3]={{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

char letters[][5]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int phNo[]={0, 1, 2};

void add(char letter){
	LIST *newNode;
	newNode=(LIST*)malloc(sizeof(LIST));
	newNode->letter=letter;
	newNode->next=NULL;
	if(!start)
		start=end=newNode;
	else
		end=end->next=newNode;
}

void del(){
	LIST* prev;
	if(start->next=NULL){
		start=NULL;
		return;
	}
	for(LIST* point=start; point->next; prev=point, point=point->next);
	prev->next=NULL;
	end=prev;
}

void print(){
	for(LIST *point=start; point; point=point->next)
		printf("%c", point->letter);
	printf("\n");
}

void possible(int start, int value){
	//printf("%d ", start);
	if(start==3){
		print();
		del();
		printf("AFTER: ");
		print();
		return;
	}
	for(int i=0; i<strlen(letters[phNo[value]]); i++){
		//printf("%d %d\n", i, strlen(letters[phNo[value]]));
		add(letters[phNo[value]][i]);
		//printf("%c", letters[phNo[value]][i]);
		possible(start+1, value+1);
	}
 	//del();
}

//void possible(int start, int number){
//	for(int i=0; i<3; i++){
//		if(start+1 <= 3){
//			//printf("%d ", numbers[start][i]);
//			possible(start+1, number*10+numbers[start][i]);
//		}else{
//		      printf("(%d %d) = %d\n", start, i, number);
//		      return;
//		}
//	}
//}
int main(){
	char temp[1];
	temp[0]='\0';
      possible(0, 0);
	return 0;
}
