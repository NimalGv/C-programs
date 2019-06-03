#include<stdio.h>
#include<malloc.h>

int main(){

    int** array;
    int row, col;
    scanf("%d", &row);
    array=(int**)malloc(row*sizeof(int*));
    scanf("%d", &col);
    for(int i=0; i<row; i++)
        array[i]=(int*)malloc(col*sizeof(int));

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            scanf("%d", &array[i][j]);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }

    return 0;
}
