#include <stdio.h>
#include <math.h>

int prime(){
	static int number=2;
	for(int i=2; i<=sqrt(number);i++){
		if(number%i==0){
			number++;
			i=1;
		}
	}
	number++;
	return number-1;
}

int fibonacci(){
	static int first=1;
	static int start=0;
	static int next=1;
	int tempStart, tempNext;
	tempStart=start;
	tempNext=next;
	if(first){
		first=0;
		return start+next;
	}
	start=next;
	next=tempStart+next;
	return tempStart+tempNext;
}

int main(){
	int term=20, ans;
	for(int i=1; i<=term; i++){
		printf("%d ", fibonacci());
		printf("%d ", prime());
		if(i%2!=0)
			ans=fibonacci();
		else
			ans=prime();
	}
	//printf("%d", ans);

	return 0;
}
