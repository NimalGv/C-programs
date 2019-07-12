#include <stdio.h>


void swap(char *a, char *b){
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void permute(char *string, int start, int end){
	if(start==end)
		printf("%s\n", string);
	else{
		for(int i=start; i<=end; i++){
			swap(&string[start], &string[i]);
			permute(string, start+1, end);
			swap(&string[start], &string[i]);
		}
	}

}



int main(){
      char string[]="ABC";
      permute(string, 0, 2);
	return 0;
}
