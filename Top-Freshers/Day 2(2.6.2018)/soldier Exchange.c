#include <stdio.h>

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}


void print(int a[], int size){
	for(int i=0; i<size; i++)
		printf("%d ", a[i]);
	printf("\n\n");
}

int main(void) {
	int soldiers[]={-12, -32, -21, -43, -10, 0,	25,	41,	20,	36, 58};
	int space, negative, tempn, positive, run, size, count=0;
    size=sizeof(soldiers)/sizeof(int);
    space=size/2;
    run=space;
	print(soldiers, size);
	for(int super=1; super<=run; super++){
        tempn=space;
		for(negative=space-1; soldiers[negative]>0 && negative>=0; negative--);
        if(!(soldiers[negative]<0)){
            negative=tempn;
        }
		swap(&soldiers[space], &soldiers[negative]);
        count++;
		space=negative;
		print(soldiers, size);
		for(int times=1; times<=super+1; times++){
			for(positive=space+1; soldiers[positive]<0 && positive<size; positive++);
            if(!(soldiers[positive]>0)){
                continue;
            }
			swap(&soldiers[space], &soldiers[positive]);
            count++;
			space=positive;
			print(soldiers, size);
		}
		for(int times=1; times<=super+1; times++){
			for(negative=space-1; soldiers[negative]>0 && negative>=0; negative--);
            if(!(soldiers[negative]<0)){
                continue;
            }
			swap(&soldiers[space], &soldiers[negative]);
            count++;
			space=negative;
			print(soldiers, size);
		}
	}
    printf("%d\n", count);
}
