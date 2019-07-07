#include <stdio.h>
#include <stdlib.h>

int *visited;
int *numbers;
int number[3];
int count=0, found=0, copy=0;

int isPythagoreanTriplet(int a, int b, int c){
	//printf("%d=%d\n", ((a*a)+(b*b)), c*c);
	if(((a*a)+(b*b))==c*c)
		return 1;
	return 0;
}

void findThree(int size){
	//for(int i=0; i<size; printf("%d ", visited[i++]));
	//printf(" : ");
	int i;
	if(count==3){
		//printf("%d %d %d \n", number[0], number[1], number[2]);
		if(isPythagoreanTriplet(number[0], number[1], number[2])){
			found=1;
			return;
		}
		return;
	}
	for(i=0; !found && i<size; i++){
		if(visited[i]==0){
			number[copy++]=numbers[i];
			visited[i]=1;
			count++;
			findThree(size);
			copy--;
			count--;
			visited[i]=0;
		}
	}
}

//    74 87 22 45 25 73

int main(){
	int testCase, size;
	scanf("%d", &testCase);
	while(testCase--){
		scanf("%d", &size);
		numbers=(int*)malloc(size*sizeof(int));
		visited=(int*)calloc(size, sizeof(int));
		for(int i=0; i<size; scanf("%d", &numbers[i++]));
		findThree(size);
		if(found)
			printf("Yes");
		else
			printf("No");
		found=0;
		count=0;
		printf("\n");
	}
	return 0;
}
