#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int *stones;
int *values;
int max=INT_MIN;
int doubleskip=0;


void hop(int position, int size){
 if(position+1 < size+1){
   values[position+1]=values[position]+values[position+1];
   hop(position+1, size);
 }
  if(position+2 < size+1){
    values[position+2]=values[position]+2*values[position+2];
    hop(position+2, size);
  }
  if(position+3 < size+1 && doubleskip!=1){
    values[position+3]=values[position]+3*values[position+3];
    doubleskip=1;
    hop(position+3, size);
  }
  doubleskip=0;

  if(position == size)
    if(max < values[size])
      max=values[size];
  values[position]=stones[position];
}

int main(void) {
  int size;
  scanf("%d", &size);
  stones=(int*)malloc((size+1)*sizeof(int));
  values=(int*)malloc((size+1)*sizeof(int));
  stones[0]=values[0]=0;
  for(int i=1; i<=size; i++){
    scanf("%d,", &stones[i]);
    values[i]=stones[i];
  }
  hop(0, size);
  printf("%d", max);
}
