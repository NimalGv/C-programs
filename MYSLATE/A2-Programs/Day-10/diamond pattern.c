#include<stdio.h>

int main(){

    int row;
    scanf("%d", &row);

    for(int i=1; i<=row; i++){
        for(int space=row-i; space>0; space--)
            printf(" ");

        for(int j=1; j<=i; j++)
            printf("%d", j);

        for(int j=i-1; j>0; j--)
            printf("%d", j);

        printf("\n");
    }
    for(int i=row-1; i>0; i--){
        for(int space=0; space<row-i; space++)
            printf(" ");

        for(int j=1; j<=i; j++)
            printf("%d", j);

        for(int j=i-1; j>0; j--)
            printf("%d", j);

        printf("\n");
    }


    return 0;
}
