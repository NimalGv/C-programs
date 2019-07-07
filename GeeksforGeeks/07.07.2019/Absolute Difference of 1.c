#include <stdio.h>
#include <stdlib.h>

int isAbsoluteDifferenceof1(long int number){
	int first=1, singleDigit=0;
	int digit1=0, digit2=0;
	while(number){
		if(!first){
			digit2=number%10;
			if(abs(digit1-digit2)!=1)
				return 0;
			digit1=digit2;
			singleDigit=0;
		}else{
			singleDigit=1;
			digit1=number%10;
			first=0;
		}
		number/=10;
//		printf("1:%d  2:%d\n", digit1, digit2);
	}
	if(singleDigit)
		return 0;
	return 1;
}



int main(){
	int testCase, size, key, notFound=1;
	long int *array;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d %d", &size, &key);
		array=(long int*)malloc(size*sizeof(long int));
		for(int i=0; i<size; scanf("%ld", &array[i++]));
		for(int i=0; i<size; i++){
			if(array[i] < key){
				if(isAbsoluteDifferenceof1(array[i])){
					printf("%ld ", array[i]);
					notFound=0;
				}
			}
		}
		if(notFound)
			printf("-1");
		printf("\n");
		free(array);
	}
	return 0;
}
