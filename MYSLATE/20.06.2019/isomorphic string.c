#include <stdio.h>



int main(){
    char string1[]="tttle", p1;
    char string2[]="paper", p2;
    int length=3, stop=0;

    printf("%s\n", string1);
    printf("%s\n", string2);

    for(int i=0; i<length; stop=0, i++){
        p1=string1[i];
        p2=string2[i];
        //printf("1%c %c\n", p1, p2);

        for(int j=i; j<length; j++){

            if(string1[j]==p1){
                if(string2[j]!=p2){
                    //printf("2%c %c\n", string1[j], string2[j]);
                    stop=1;
                    break;
                }
            }
        }
        if(stop)
            break;
        printf("\n");
    }
    if(stop)
        printf("NO");
    else
        printf("YES");


    return 0;
}
