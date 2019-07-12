#include <stdio.h>
#include <stdlib.h>



int answer=0;
int found=0;
int *NUMBER;
int *numberInDigits;

typedef struct digitscheck{
	int digit;
	int visited;
}DIGITS;
DIGITS *digitList;

int findSmallest(int digit, int no_of_digits){
	for(int i=0; i<no_of_digits; i++){
		if(digitList[i].digit < digit && digitList[i].visited==0){
			digitList[i].visited=1;
			return i;
		}
	}
	return -1;
}

int findEqual(int digit, int no_of_digits){
	for(int i=0; i<no_of_digits; i++){
		if(digitList[i].digit == digit && digitList[i].visited==0){
			digitList[i].visited=1;
			return i;
		}
	}
	return -1;
}

int findLargest(int digit, int no_of_digits){
	for(int i=0; i<no_of_digits; i++){
		if(digitList[i].digit > digit && digitList[i].visited==0){
			digitList[i].visited=1;
			return i;
		}
	}
	return -1;
}

void findNextBiggest(int position, int no_of_digits){
	int smallDigitPos, equalDigitPos, largerDigitPos;
	smallDigitPos=findSmallest(numberInDigits[position], no_of_digits);
	if(smallDigitPos!=-1 && !found){
		answer=answer*10+digitList[smallDigitPos].digit;
		findNextBiggest(position+1, no_of_digits);
		digitList[smallDigitPos].visited=0;
	}

	equalDigitPos=findEqual(numberInDigits[position], no_of_digits);
	if(equalDigitPos!=-1 && !found){
		answer=answer*10+digitList[equalDigitPos].digit;
		findNextBiggest(position+1, no_of_digits);
		digitList[equalDigitPos].visited=0;
	}

	largerDigitPos=findLargest(numberInDigits[position], no_of_digits);
	if(largerDigitPos!=-1 && !found){
		answer=answer*10+digitList[largerDigitPos].digit;
		findNextBiggest(position+1, no_of_digits);
		digitList[largerDigitPos].visited=0;
	}

	if(position==no_of_digits){
		if(answer > *NUMBER){
			printf("\nFound: %d", answer);
			found=1;
		}
	}
	answer/=10;
}

void sortList(int size){
	for(int i=0; i<size-1; i++){
		for(int j=i+1; j<size; j++){
			if(digitList[i].digit > digitList[j].digit){
				int temp=digitList[i].digit;
				digitList[i].digit=digitList[j].digit;
				digitList[j].digit=temp;
			}
		}
	}
//	for(int i=0; i<size; i++)
//		 printf("%d (%d)\n", digitList[i].digit, digitList[i].visited);
}

int main(){
	int number, temp, i;
	int no_of_digits=0;
	printf("Enter the Number: ");
	scanf("%d", &number);
	NUMBER=&number;

	temp=number;
	while(temp){
		temp/=10;
		no_of_digits++;
	}

	digitList=(DIGITS*)malloc(sizeof(DIGITS));
	numberInDigits=(int*)malloc(sizeof(int));

	temp=number;
	i=no_of_digits-1;
	while(temp){
		digitList[i].digit=temp%10;
		numberInDigits[i]=temp%10;
		digitList[i].visited=0;
		temp/=10;
		i--;
	}

	sortList(no_of_digits);

	findNextBiggest(0, no_of_digits);
	if(!found)
		printf("Not Found");
	return 0;
}
