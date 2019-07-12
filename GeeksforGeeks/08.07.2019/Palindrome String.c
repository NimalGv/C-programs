#include <stdio.h>
#include <stdlib.h>

int isPalindrome(char *string, int start, int end){
	while(start<end){
		if(string[start]!=string[end])
			return 0;
		start++;
		end--;
	}
	return 1;
}

int main(){
      int testCase, size;
      char *string;
      scanf("%d", &testCase);
      while(testCase--){
		scanf("%d", &size);
		string=(char *)calloc(size, sizeof(char));
		scanf("%s", string);
		if(isPalindrome(string, 0, size-1))
			printf("Yes");
		else
			printf("No");
		printf("\n");
		free(string);
      }
	return 0;
}
