#include<stdio.h>



int main(){
    char number[]="1110110101001111110101011101010";
    int length=sizeof(number)/sizeof(char);
    int count, j, previous=0, start;
    printf("%s\n", number);
    printf("LEN : %d\n", length);
    for(start=0; start<length; previous++, start++){
        if(number[start]=='0')
            break;
    }
    for(int i=start; i<length; i++){
        if(number[i]=='0'){
            j=i+1;
            count=0;
            while(number[j]!='0' && j<length-1){
                count++;
                printf("%d\t", j);
                j++;
            }
            printf("\n%d\n", count);
            printf("Max 1's: %d\n\n\n", count+1+previous);
            previous=count;
            count=0;
        }
    }


    return 0;
}
