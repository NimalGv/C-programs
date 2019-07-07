#include <stdio.h>


int main(){
      int matrix1[][2]={
					{1, 2},
					{3, 4}};

      int matrix2[][2]={
					{2, 3},
					{4, 5}};
//
//	for(int i=0; i<2; printf("\n"), i++)
//		for(int j=0; j<2; j++)
//			printf("%d ", matrix1[i][j]+matrix2[i][j]);
	int ans=0;
	for(int i=0; i<2; printf("\n"), i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				ans+=matrix1[i][k]*matrix2[k][j];
			}
			printf("%d ", ans);
			ans=0;
		}
	}
//
//	for(int i=0; i<2; printf("\n"), i++)
//		for(int j=0; j<2; printf("%d ", matrix1[i][j++]));

	return 0;
}
