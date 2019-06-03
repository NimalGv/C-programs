#include<stdio.h>
int IsPrime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return 0;
    }
    return 1;
}



int main(){
    int num;
    scanf("%d",&num);
    if(num%2==0 && num>=4)
        printf("Yes");
    else{
        if(IsPrime(num-2))
            printf("Yes");
        else
            printf("No");
    }

}

/*
    1.Any even number greater than or equal to 4 can always be written as sum of two primes
          even : even+even and odd+odd;

    2.The odd number can be written as sum of two primes if the number-2 is a prime number, because
          odd : odd+even and even+odd;
          so,    IsPrime(number-2)
*/
