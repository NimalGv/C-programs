#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contain{
	char letter;
	struct contain *next;
}LIST;

LIST *start, *end;

char letters[][5]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
int *phNo;

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
	for(LIST* point=start; point->next; prev=point, point=point->next);
	prev->next=NULL;
	end=prev;
}

void print(){
	for(LIST *point=start; point; point=point->next)
		printf("%c", point->letter);
	printf(" ");
}

void possible(int begin, int value, int noOfdigits){
	if(begin==noOfdigits){
		print();
		return;
	}
	for(int i=0; i<strlen(letters[phNo[value]]); i++){
		add(letters[phNo[value]][i]);
		possible(begin+1, value+1, noOfdigits);
		if(begin==0)
			start=NULL;
		else
			del();
	}
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
	int noOfdigits, testCase, number;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &noOfdigits);
		phNo=(int*)malloc(noOfdigits*sizeof(int));
		for(int i=0; i<noOfdigits; i++){
			scanf("%d", &number);
			phNo[i]=number-2;
		}
		possible(0, 0, noOfdigits);
	}
	return 0;
}
