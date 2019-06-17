#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int testcase, size, number;
	scanf("%d", &testcase);
	while(testcase--){
		scanf("%d %d", &size, &number);
		int *array=(int*)malloc(size*sizeof(int));
		for(int i=0; i<size; scanf("%d", &array[i++]));
		int i;
		int front, back;
		for(i=0; i<size; i++)
			if(array[i]>number)
				break;
		if(i==0)
			printf("%d\n", array[i]);
		else if(i==size)
			printf("%d\n", array[i-1]);
		else if((array[i]-number)<=(number-array[i-1]))
			printf("%d\n", array[i]);
		else
			printf("%d\n", array[i-1]);
	}

	return 0;
}
