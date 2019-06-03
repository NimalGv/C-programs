#include<stdio.h>
int main(){
    int a[]={1, 2, 3, 4, 5, 5, 15, 4, 3, 2, 1};
    int size, xor=0;

    size=sizeof(a)/sizeof(int);

    for(int i=0; i<size; i++){
            xor=xor^a[i];
    }
    printf("%d", xor);


}
