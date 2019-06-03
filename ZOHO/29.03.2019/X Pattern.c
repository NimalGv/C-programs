#include<stdio.h>

int main(){

    char string[]="NIMAL";
    int size;
    for(size=0; string[size]; size++);

    for(int i=0; i<size; i++){

        for(int j=0; j<size; j++){
            if(i==j){
                printf("%c", string[i]);
            }else if(j==size-1-i){
                printf("%c", string[j]);
            }else{
                printf(" ");
            }
        }
        printf("\n");

    }

    return 0;
}
