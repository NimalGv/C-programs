#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isAscending(int array[], int start, int end){
	for(int i=start; i<end-1; i++)
		if(array[i]>array[i+1])
			return 0;
	return 1;
}

int main(){
	int max=INT_MIN, maxPos, testCase, *array, size;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &size);
		array=(int*)malloc(size*sizeof(int));
		for(int i=0; i<size; scanf("%d", &array[i++]));

		for(int i=0; i<size; i++){
			if(max<array[i]){
				max=array[i];
				maxPos=i;
			}
		}

		if(maxPos >= size/2){
			if(isAscending(array, 0, maxPos+1)){
				if(maxPos==size-1)
					printf("%d 1", max);
				else
					printf("%d 4", max);
			}else{
				if(maxPos==0)
					printf("%d 2", max);
				else
					printf("%d 3", max);
			}
		}else{
			if(isAscending(array, maxPos+1, size)){
				if(maxPos==size-1)
					printf("%d 1", max);
				else
					printf("%d 4", max);
			}else{
				if(maxPos==0)
					printf("%d 2", max);
				else
					printf("%d 3", max);
			}
		}
		max=INT_MIN;
		maxPos=0;
		printf("\n");
		free(array);
	}


	return 0;
}
