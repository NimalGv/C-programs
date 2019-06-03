#include<stdio.h>

struct denomination{
	int value;
	int no_of_notes;
	int total;
};

typedef struct denomination notes;
typedef notes *  notesPTR;

notes currency[6];

int initialize(){
	int note[]={1000, 500, 100, 50, 20, 10};
	int noOfNotes[]={1, 2, 5, 0, 10, 10};
	for(int i=0; i<6; i++){
		currency[i].value=note[i];
		currency[i].no_of_notes=noOfNotes[i];
		currency[i].total=currency[i].value*currency[i].no_of_notes;
	}
}

void printNotes(){
	for(int i=0; i<6; i++){
		printf("%4d %4d %4d\n", currency[i].value, currency[i].no_of_notes, currency[i].total);
	}
}

int main(){
	initialize();
	printNotes();
	return 0;
}
