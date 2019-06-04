#include <stdio.h>
#include <math.h>

int isPrime(int n){
	for(int i=2; i<=sqrt(n); i++)
		if(n%i==0)
		return 0;
	return 1;

}

int find(int count){
  int check=1;
  for(int i=3; ;i+=2){
	  if(isPrime(i)){
		  check++;
		  if(check==count)
		  	return i;
	  }
  }
}

int main(void) {

  int x=0, y=0;
  int x1=-136, y1=136;
  int i=1, j;
  int odd=1, count=1;
  //scanf("%d %d", &x1, &y1);

  while(x!=x1 || y!=y1){
	  if(i%2==0)
	  	odd=0;
	  else
	  	odd=1;
	  j=0;
	  while((x!=x1 || y!=y1) && j<i){
		if(odd){
			x++;
			//printf("(%d, %d)\n", x, y);
			count++;
		}
		else{
			x--;
			//printf("(%d, %d)\n", x, y);
			count++;
		}
		j++;
	  }
	  j=0;
	  while((x!=x1 || y!=y1) && j<i){
		if(odd){
			y++;
			count++;
		}
		else{
			y--;
			count++;
		}
		//printf("(%d, %d)\n", x, y);
		j++;
	  }
	  //printf("\n");
	i++;  
  }
  printf("Count: %d", count);
  printf("\nNumber: %d", find(count));
  
}

