#include<stdio.h>
void printImage(int **img,int no_rows,int no_cols  )
{
    int row,col;
    for(printf("\n"),row = 0 ; row <no_rows; row++,printf("\n"))
     for(col = 0; col< no_cols ; col++)
      if(img[row][col]==1)
         printf("*");//printf("%d ",img[row][col]);
      else
        printf(" ");

}
void swap(int * arr ,int ind1, int ind2)
{
    int temp;
    temp = arr[ind1];
    arr[ind1]= arr[ind2];
    arr[ind2]=temp;
}
void arrayReverser( int * arr , int size  )
{
    int st,end;
    for(st=0, end= size-1;st<end;swap(arr,st,end),st++,end--);
}
int main()
{
int image[11][7]={
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

    int ** trans_img=NULL;
   int ** img=NULL;
    int rows,cols,row_ctr,row,col,trans_rows,trans_cols,rot=0,st,end;
    int*tempPtr;
    rows=11;
    cols=7;
    trans_rows=cols;
    trans_cols = rows;
    rot=1;//0->right, 1->left
//2d dynamic Allocation for img since size will be varying
    img = (int**)malloc( rows * sizeof(int*));
    for(row_ctr = 0 ;row_ctr < rows ; row_ctr++)
        img[row_ctr]=(int * )malloc(cols*sizeof(int));
//2d Copy
    for(row = 0 ; row <rows; row++)
     for(col = 0; col< cols ; col++)
       img[row][col] =image[row][col];
//2d dynamic Allocation for transpose since row & col size will be interchanged
    trans_img = (int**)malloc( cols * sizeof(int*));
    for(row_ctr = 0 ;row_ctr < cols ; row_ctr++)
        trans_img[row_ctr]=(int * )malloc(rows*sizeof(int));
//transpose of img
    for(row = 0 ; row <rows; row++)
     for(col = 0; col< cols ; col++)
       trans_img[col][row] =img[row][col];

    //printImage(image,rows,cols);
    printImage(trans_img,trans_rows,trans_cols);
 rot=1;
  if(rot ==0 )//right
       for(row= 0; row< trans_rows;row++ )
           arrayReverser(trans_img[row] ,trans_cols);
  else //rot==1 =>left
      {
         for(st = 0 , end = trans_rows-1 ; st<end ; st++,end--)
          {
              tempPtr = trans_img[st];
              trans_img[st] = trans_img[end];
              trans_img[end] = tempPtr;
          }
      }

    for(row= 0; row< trans_rows;row++ )
           arrayReverser(trans_img[row] ,trans_cols);

    printImage(trans_img,trans_rows,trans_cols);

    return 0 ;
}
