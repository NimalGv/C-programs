#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct map{
	char word[50];
	int occured;
	struct map *next;
}NODE;

typedef struct head{
	NODE *start;
}HEAD;
HEAD list[3];

void add(char words[], int sentence){
	NODE *newNode, *point;
	newNode=(NODE*)malloc(sizeof(NODE));
	strcpy(newNode->word, words);
	newNode->occured=1;
	newNode->next=NULL;
	if(!list[sentence].start)
		list[sentence].start=newNode;
	else{
		for(point=list[sentence].start; point->next; point=point->next);
		point->next=newNode;
	}
}


void separateWords(char sentence[], int sentenceNo){
	int copy=0;
	char word[50];

	for(int i=0; sentence[i]; i++){
		if(sentence[i]==' '){
			word[copy]='\0';
			add(word, sentenceNo);
			//printf("%s\t", word);
			copy=0;
		}else
			word[copy++]=sentence[i];
	}
	word[copy]='\0';
	add(word, sentenceNo);
	//printf("%s", word);
}

void findWordsOccuredThreeTimes(){
	NODE *point1, *point2, *point3;
	for(point1=list[0].start; point1; point1=point1->next){
		for(point2=list[1].start; point2; point2=point2->next){
			if(strcasecmp(point1->word, point2->word)==0){
				for(point3=list[2].start; point3; point3=point3->next){
					if(strcasecmp(point1->word, point3->word)==0){
						point1->occured=3;
						point2->occured=3;
						point3->occured=3;
					}
				}
			}
		}
	}
	for(int i=0; i<3; i++){
		for(point1=list[i].start; point1->next; point2=point1, point1=point1->next){
			if(point1->occured==3){
				if(point1==list[i].start)
					list[i].start=point1->next;
				else{
					point2->next=point1->next;
					point1=list[i].start;
				}
			}
		}
	}
}

void printList(){
	NODE *point;
	for(int i=0; i<3; printf("\n\n"), i++)
		for(point=list[i].start, printf("Sentence %d:  ", i+1); point; point=point->next)
			printf("%s ", point->word, point->occured);
}

int main(){
        char sentenceOne[]="Everyday i wake up in the morning";
        int sentenceOneLength=strlen(sentenceOne);
        char sentenceTwo[]="Not Everyday i don't wake up in night";
        int sentenceTwoLength=strlen(sentenceTwo);
        char sentenceThree[]="You and i everyday are best friends in school days";
        int sentenceThreeLength=strlen(sentenceThree);
        separateWords(sentenceOne, 0);
        separateWords(sentenceTwo, 1);
        separateWords(sentenceThree, 2);
        findWordsOccuredThreeTimes();
        printList();
	return 0;
}
