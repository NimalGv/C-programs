#include<stdio.h>

int main(){

int num = 800, factor;

for(factor=2;   num!=1     ; factor++)
while(num % factor == 0)
   num=num/ factor;

return 0;
}
