#include<stdio.h>
#include<malloc.h>
#include<string.h>

int count=0;

struct family{
    char son[50];
    char father[50];
};

typedef struct family family;
typedef family * familyptr;

void printFamily(familyptr family1, int size){
    for(int i=0; i<size; i++){
            printf("%s\t%s\n", family1[i].son, family1[i].father);
    }
    printf("\n\n");
}

void isFather(familyptr family1, int size, char name[]){
    printf("%s\n", name);
    for(int i=0; i<size; i++){
        if(strcmp(name, family1[i].father)==0){
            count++;
            isFather(family1, size, family1[i].son);
        }

    }

    return;
}

int main(){
    familyptr family1;
    int size;
    char search[50];
    scanf("%d", &size);
    family1=(familyptr)malloc(size*sizeof(family));
    for(int i=0; i<size; i++){
        scanf("%s %s", family1[i].son, family1[i].father);
    }
    printFamily(family1, size);
    printf("Search: ");
    scanf("%s", search);
    isFather(family1, size, search);
    printf("\n%d", count);
    return 0;

}
