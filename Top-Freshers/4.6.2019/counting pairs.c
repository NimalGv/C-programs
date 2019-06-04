#include <stdio.h>

int main(void) {
  int numbers[]={1, 11, 111}, digit1, digit2, count=0;
  int size=sizeof(numbers)/sizeof(int);

  for(int i=0; i<size-1; i++){
	  for(int j=i+1; j<size; j++){
		  //printf("%d %d\n", numbers[i], numbers[j]);
		  if(numbers[i]<numbers[j]){
			  int num1=numbers[i];
			  int num2=numbers[j];
			  while(num1){
				  digit1=num1%10;
				  //printf("digit1:%d \n", digit1);
				  while(num2){
					  digit2=num2%10;
					  //printf("digit2:%d \n", digit2);
					  if(digit1==digit2){
						  //printf("1:%d %d\n", digit1, digit2);
						  count++;
						  goto here;
					  }
					  num2/=10;
				  }
				  num2=numbers[j];
				  num1/=10;
			  }
		  }
		  here: printf("");
	  }
  }
  printf("%d", count);

}
