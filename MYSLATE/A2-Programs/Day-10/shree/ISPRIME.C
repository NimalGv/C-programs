#include<stdio.h>
#include<math.h>


int isPrime(int num)
{
  int till, factor;
  if(num == 1 ) return 0;
  if(num == 2 || num == 3 || num == 5)return 1;
  if(num % 2 == 0) return 0;
  till = sqrt(num);
  if(num % 6 == 1 || num % 6 == 5) // check for PRIME candidate
  {
     for(factor =3; factor <= till; factor+=2)
     if(num % factor == 0) return 0;

     return 1;
  }

}

int main(int argc, char *argv[])
{
int num;
num = atoi(argv[1]);
if(isPrime(num) == 1) printf("Prime");
else printf("Not Prime");
}