#include<stdio.h>

int power(int c){
	int ans=1;
	while(c){
		ans*=10;
		c--;
	}
	return ans;
}

int main(){
	int num=3265;
	int temp, digit;
	
	while(num){
		int answer=0, i=0;
		temp=num;
		while(num){
			digit=num%10;
			if(digit>0)
				answer=answer+power(i);
			i++;
			num/=10;
		}
		printf("%d\n", answer);
		num=temp;
		num-=answer;
	}
	
	return 0;
}
