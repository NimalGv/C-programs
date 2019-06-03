 #include<stdio.h>

 int power(int num){
     int pow=1;
     for(int i=1;i<=num;i++)
        pow*=10;
     return pow;
 }

 int main(){
    long long num, temp;
    int  pos1, pos2, length=0, digit1, digit2;
    scanf("%lld %d %d", &num, &pos1, &pos2);
    temp=num;
    while(temp){
        temp/=10;
        length++;
    }

    temp=num;
    pos1=(length-pos1)+1;
    pos2=(length-pos2)+1;
    printf("%d\n", pos1);
    printf("%d\n", pos2);

    digit1=(num/power(pos1))%10;
    num=num-(digit1*(power(pos1)));
    digit2=(num/power(pos2))%10;
    num=num-(digit2*(power(pos2)));
    //printf("%d", num);

    num=num+(digit2*(power(pos1)));
    num=num+(digit1*(power(pos2)));
    printf("%d", num);


 }
