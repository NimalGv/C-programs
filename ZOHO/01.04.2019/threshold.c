#include<stdio.h>

int count=0;

void calculate(int number, int threshold){
	while(number>0){
		if(number-threshold>=0){
			number-=threshold;
			printf("Threshold: %d\n", threshold);
			count++;
		}else{
			threshold--;
		}
	}
}



int main(){
	int threshold, size;
	int array[]={67, 743, 73, 634, 89, 734, 9, 76, 90, 36, 65, 34};
	size=sizeof(array)/sizeof(int);
	threshold=12;
	for(int i=0; i<size; i++)
		calculate(array[i], threshold);
		
	printf("Count: %d", count);
	
}
