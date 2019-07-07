#include <stdio.h>
#include <stdlib.h>

int visited[5];
int numbers[]={6, 2, 3, 4, 5};
int count=0, found=0;

int isPythagoreanTriplet(int a, int b, int c){
	if(((a*a)+(b*b))==c*c)
		return 1;
	return 0;
}

void findThree(int index, int size){
	int i;
	if(count==3){
		printf("**\n");
		int number[3], copy=0;
		for(int i=0; i<5; i++)
			if(visited[i]==1)
				number[copy++]=numbers[i];
		printf("%d %d %d\n", number[0], number[1], number[2]);
		if(isPythagoreanTriplet(number[0], number[1], number[2])){
			found=1;
			return;
		}
		return;
	}
	for(i=index; !found && i<size; i++){
		if(visited[i]==0){
			printf("%d\t", i);
			visited[i]=1;
			count++;
			findThree(i+1, size);
			count--;
			visited[i]=0;
		}
	}
}


int main(){
	int testCase;

	findThree(0, 5);
	if(found)
		printf("YES");
	else
		printf("NO");
	return 0;
}
