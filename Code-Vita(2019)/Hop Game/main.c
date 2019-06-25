#include <stdio.h>
#include <limits.h>


int stones[7]={0, 4, 5, 6, 7, 4, 5};
int values[7]={0, 4, 5, 6, 7, 4, 5};
int max=INT_MIN;
int doubleskip=0;

void print(){
  printf("\n Values: ");
  for(int i=0; i<7; printf("%d ", values[i]), i++);
  printf("\n");
}


void hop(int position){
 printf("(%d)\n", position);
 print();
 if(position+1 < 7){
   values[position+1]=values[position]+values[position+1];
   hop(position+1);
 }

  //printf("Hop: %d\n", single);
  if(position+2 < 7){
    values[position+2]=values[position]+2*values[position+2];
    printf("%d:", position);
    hop(position+2);
  }
  if(position+3 <7 && doubleskip!=1){
    values[position+3]=values[position]+3*values[position+3];
    printf("%d:", position);
    doubleskip=1;
    hop(position+3);
  }
  doubleskip=0;

  if(position==6)
    if(max < values[6])
      max=values[6];
  values[position]=stones[position];
  printf("END:");
  print();
}

int main(void) {

  hop(0);
  print();
  printf("MaX: %d", max);
}
