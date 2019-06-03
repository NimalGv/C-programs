#include<stdio.h>
#include<malloc.h>

void print_image(int **array, int row, int col){

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
                if(array[i][j]==1)
                    printf("* ");
                else
                    printf("  ");
        }
        printf("\n");
    }
}

void swap(int * arr ,int ind1, int ind2)
{
    int temp;
    temp = arr[ind1];
    arr[ind1]= arr[ind2];
    arr[ind2]=temp;
}

void row_reverse(int* array, int size){

    int end=size-1, temp;
    for(int i=0; i<end; i++, end--)
        swap(array, i, end);

}

int main(){

    int row=11, col=7;
    int image[11][7]={
                    {1,0,0,0,0,0,1},
                    {1,0,0,0,0,1,0},
                    {1,0,0,0,1,0,0},
                    {1,0,0,1,0,0,0},
                    {1,0,1,0,0,0,0},
                    {1,1,0,0,0,0,0},
                    {1,0,1,0,0,0,0},
                    {1,0,0,1,0,0,0},
                    {1,0,0,0,1,0,0},
                    {1,0,0,0,0,1,0},
                    {1,0,0,0,0,0,1}

                   };
/*    int image[11][7]={
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

                   };   */
    int **image1=NULL;
    int **imageright=NULL;
    int **imageleft=NULL;
    int **imagedown=NULL;
    int right_row=col, right_col=row, left_col=row, left_row=col, temp;

    //image1  memory allocation
    image1=(int**)malloc(row*sizeof(int*));
    for(int i=0; i<row; i++)
        image1[i]=(int*)malloc(col*sizeof(int));

    //imageright  memory allocation
    imageright=(int**)malloc(right_row*sizeof(int*));
    for(int i=0; i<right_row; i++)
        imageright[i]=(int*)malloc(right_col*sizeof(int));

    //imageleft  memory allocation
    imageleft=(int**)malloc(left_row*sizeof(int*));
    for(int i=0; i<left_row; i++)
        imageleft[i]=(int*)malloc(left_col*sizeof(int));


    //image copy to image1
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            image1[i][j]=image[i][j];

    //transposing the image1
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            imageright[j][i]=image[i][j];

    print_image(image1, row, col);

    //reversing each row gives imageright
    for(int i=0; i<right_row; i++){
        row_reverse(imageright[i], right_col);
    }

    printf("\n");
    print_image(imageright, right_row, right_col);

    //rotating left side
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            imageleft[col-1-j][i]=image1[i][j];
        }
    }

    printf("\n");
    print_image(imageleft, left_row, left_col);


    return 0;
}
