#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b){
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int nextVowelForward(char * string, int start, int end){
	for(start; start < end; start++)
		if(string[start]=='a' || string[start]=='e' || string[start]=='i' || string[start]=='o' || string[start]=='u')
			break;
	return start;
}

int nextVowelReverse(char * string, int start, int end){
	for(start; start > end; start--)
		if(string[start]=='a' || string[start]=='e' || string[start]=='i' || string[start]=='o' || string[start]=='u')
			break;
	return start;
}


void swapVowels(char *string, int *visited, int start, int end){
	int size=end+1;
	while(start < end){
		start=nextVowelForward(string, start, end);
		end=nextVowelReverse(string, end, start);
		visited[start]=1;
		visited[end]=1;
//		printf("%c %c\n", string[start++], string[end--]);
		swap(&string[start++], &string[end--]);
//		printf("\n");
	}
}

int main(){
	int testCase;
	scanf("%d", &testCase);
	while(testCase--){
		char string[1000];
		int size, *visited;
		scanf("%s", string);
		size=strlen(string);
		visited=(int*)calloc(size, sizeof(int));
		swapVowels(string, visited, 0, size-1);
		printf("%s\n", string);
	}
	return 0;
}
