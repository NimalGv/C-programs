#include <stdio.h>
#include <string.h>

typedef struct numberpad{
    int KeyPadNumber;
    char start;
    int count;
    char string[5];
}NUMBERPAD;

NUMBERPAD NumPad[]={{0, ' ', 1, " "},
                    {2, 'A', 3, "ABC"},
                    {3, 'D', 3, "DEF"},
                    {4, 'G', 3, "GHI"},
                    {5, 'J', 3, "JKL"},
                    {6, 'M', 3, "MNO"},
                    {7, 'P', 4, "PQRS"},
                    {8, 'T', 3, "TUV"},
                    {9, 'W', 4, "WXYZ"}};

void printKeys(int position, char letter){
    int stringLength=NumPad[position].count, i;
    for(i=0; i<stringLength; i++)
        if(letter==NumPad[position].string[i])
            break;
    for(int j=0; j<=i; j++)
        printf("%d", NumPad[position].KeyPadNumber);
}

void findPosition(char input[]){
    int stringLength=strlen(input);
    for(int i=0; i<stringLength; i++){
        for(int position=0; position<8; position++)
            if(input[i]<NumPad[position].start+NumPad[position].count){
                printKeys(position, input[i]);
                printf(" ");
                break;
            }
    }
}

int main(){
    char input[]="NIMAL";
//  scanf("%s", input);
    findPosition(input);

    return 0;
}
