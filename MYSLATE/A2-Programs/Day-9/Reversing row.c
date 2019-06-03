#include<stdio.h>
#include<malloc.h>

int main(){
    /*int *array;
    array=(int *)malloc(5*sizeof(int));     */
    int image1[11][7]={
                    {1,1,1,1,1,1,1},
                    {0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,1},
                    {0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1},
                    {1,0,0,0,0,0,1},
                    {1,0,0,0,0,0,1},
                    {1,0,0,0,0,0,1},
                    {1,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1}

                   };
    int imageleft[7][11]={0};
    int imagedown[11][7]={0};
    int row=11, col=7;
    int temp;
    for(int i=0; i<11; i++){
            for(int j=0; j<7; j++)
                printf("%d ", image1[i][j]);
    printf("\n");
    }
    printf("\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            imageleft[col-1-j][i]=image1[i][j];
        }
    }

    for(int i=0; i<7; i++){
            for(int j=0; j<11; j++)
                printf("%d ", imageleft[i][j]);
    printf("\n");
    }

    printf("\n");
    for(int i=0; i<7; i++){
        for(int j=0; j<11; j++){
            imagedown[col-1-j][i]=imageleft[i][j];
        }
    }

    for(int i=0; i<11; i++){
            for(int j=0; j<7; j++)
                printf("%d ", imagedown[i][j]);
    printf("\n");
    }
}
