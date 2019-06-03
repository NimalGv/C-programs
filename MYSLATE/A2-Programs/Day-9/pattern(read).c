#include<stdio.h>
#include<string.h>

int main(){

    char read[100]="1";
    char write[100];

    int read_index, write_index, count;
    char point;

    printf("%s\n", read);
    for(int limit=0; limit<10;limit++){
        read_index=write_index=count=0;
        point=read[0];
        while(1){

            while(read[read_index]==point){

                count++;
                read_index++;

            }
            write[write_index++]=count+48;
            write[write_index++]=point;
            if(read[read_index]!=NULL){

                    point=read[read_index];
                    count=0;

            }else
                break;
        }

            write[write_index]=NULL;
            printf("%s\n", write);
            strcpy(read, write);
            write[0]=NULL;
    }

}
