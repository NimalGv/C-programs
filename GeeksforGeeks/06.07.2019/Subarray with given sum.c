#include <stdio.h>
#include <stdlib.h>


int main(){
//      int sum=12, size=5, gotSum=0, found=0;
//      int array[]={1, 2, 3, 7, 5};
      int testCase, size, *array, found=0, gotSum=0, sum;
      scanf("%d", &testCase);
      while(testCase--){
		scanf("%d %d", &size, &sum);
		array=(int*)malloc(size*sizeof(int));
		for(int i=0; i<size; scanf("%d", &array[i++]));
		for(int i=0; i<size; gotSum=0, i++){
			for(int j=i; j<size; j++){
				gotSum+=array[j];
				if(gotSum==sum){
					found=1;
					printf("%d %d", i+1, j+1);
					break;
				}
			}
			if(found)
				break;
		}
		if(!found)
			printf("-1");
		found=0;
		gotSum=0;
		printf("\n");
      }

	return 0;
}
