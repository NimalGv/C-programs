#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *array, min, minpos, size, i, pos, testcase;
  scanf("%d", &testcase);
  while(testcase--){
	scanf("%d", &size);
	array=(int *)malloc(size*sizeof(int));
	int *pendulum=(int *)malloc(size*sizeof(int));
	for(int i=0; i<size; scanf("%d", &array[i++]));
	if(size%2==0)
		pos=(size-1)/2;
	else
		pos=size/2;
	for(int off=0; off<size; off++){
		for(i=0, min=10000; i<size; i++){
			if(array[i]==0)
				continue;
			if(min>array[i]){

				min=array[i];
				minpos=i;
			}
		}
		array[minpos]=0;
		if(off<2){
			pendulum[pos+off]=min;
			pos+=off;
		}else if(off%2==0){
			pendulum[pos-off]=min;
			pos-=off;
		}else{
			pendulum[pos+off]=min;
			pos+=off;
		}
	}
	for(int i=0; i<size; i++)
		printf("%d ", pendulum[i]);
	printf("\n");
  }
  return 0;
}
