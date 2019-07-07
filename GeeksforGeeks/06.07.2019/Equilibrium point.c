#include <stdio.h>
#include <stdlib.h>


int leftSum(int *array, int position){
	int sum=0;
	for(int i=position-1; i>=0; sum+=array[i--]);
	return sum;
}

int rightSum(int *array, int position, int size){
	int sum=0;
	for(int i=position+1; i<size; sum+=array[i++]);
	return sum;
}

int findEquilibrium(int *array, int position, int size){
	int lSum,rSum;
	lSum=leftSum(array, position);
	rSum=rightSum(array, position, size);
	if(lSum==rSum)
		return position+1;
	if(lSum > rSum)
		return findEquilibrium(array, position-1, size);
	else
		return findEquilibrium(array, position+1, size);
}

int main(){
      int *array, size, position, testCase;
      scanf("%d", &testCase);
      while(testCase--){
		scanf("%d", &size);
		array=(int*)malloc(size*sizeof(int));
		for(int i=0; i<size; scanf("%d", &array[i++]));
		position=size/2;
		printf("%d", findEquilibrium(array, position, size));
		printf("\n");
		free(array);
      }
	return 0;
}
