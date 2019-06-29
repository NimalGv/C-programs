#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

typedef struct check{
    int digit;
    int visited;
}CHECK;

CHECK *DigitCheck;  //[]={{5, 0}, {9, 0}, {6, 0}, {4, 0}};
int *Digits;
int *Original;
int number=0, found=0;

void initialize(int size){
    for(int i=0; i<size; i++)
        DigitCheck[i].visited=0;
}

int findEqual(int number, int size){
    for(int i=0; i<size; i++){
        if(number==DigitCheck[i].digit && !DigitCheck[i].visited){
            DigitCheck[i].visited=1;
            return i;
        }
    }
    return -1;
}

int findSmall(int number, int size){
    for(int i=0; i<size; i++){
        if(number > DigitCheck[i].digit && !DigitCheck[i].visited){
            DigitCheck[i].visited=1;
            return i;
        }
    }
    return -1;
}

int findGreat(int number,  int size){
    for(int i=0; i<size; i++){
        if(number < DigitCheck[i].digit && !DigitCheck[i].visited){
            DigitCheck[i].visited=1;
            return i;
        }
    }
    return -1;
}

void findDigit(int digitPos, int size){
    int EqualPos, SmallPos, GreatPos;
    SmallPos=findSmall(Digits[digitPos], size);
    if(SmallPos!=-1 && !found){
        number=number*10+DigitCheck[SmallPos].digit;
        findDigit(digitPos+1, size);
        DigitCheck[SmallPos].visited=0;
    }
    EqualPos=findEqual(Digits[digitPos], size);
    if(EqualPos!=-1 && !found){
        number=number*10+DigitCheck[EqualPos].digit;
        findDigit(digitPos+1, size);
        DigitCheck[EqualPos].visited=0;
    }
    GreatPos=findGreat(Digits[digitPos], size);
    if(GreatPos!=-1 && !found){
        number=number*10+DigitCheck[GreatPos].digit;
        findDigit(digitPos+1, size);
        DigitCheck[GreatPos].visited=0;
    }

    if(digitPos==size){
        if(number > *Original){
            found=1;
            printf("%d\n", number);
        }

    }
    number/=10;

}

int main(){
    int number1, number2, temp, size=0;
    scanf("%d", &number1);
    scanf("%d", &number2);
    Original=&number2;
    temp=number1;
    while(temp){
        size++;
        temp/=10;
    }
    DigitCheck=(CHECK*)malloc(size*sizeof(CHECK));
    Digits=(int*)malloc(size*sizeof(int));
    initialize(size);
    temp=number1;
    int index=0;
    while(temp){
        DigitCheck[index++].digit=temp%10;
        temp/=10;
    }
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(DigitCheck[i].digit > DigitCheck[j].digit){
                int temp=DigitCheck[i].digit;
                DigitCheck[i].digit=DigitCheck[j].digit;
                DigitCheck[j].digit=temp;
            }
        }
    }
    temp=number2;
    index=size-1;
    while(temp){
        Digits[index--]=temp%10;
        temp/=10;
    }
    findDigit(0, size);
    if(!found)
        printf("-1\n");
    return 0;
}
