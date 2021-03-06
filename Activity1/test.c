#include "My_string.c"
#include "My_utils.c"
#include "Bi_tmask.c"
#include <stdio.h>
int main() {
  char str[]="Devan";
  int prime=5,palindrome=151,f=4,num1=5,k=1;
  

  printf("length of the string is %lu\n ",mystrlen(str));
  

  if(isPrime(prime))
      printf("the number is prime\n");

  if(ispalindrome(palindrome))
      printf("the number is palindrome\n");


  printf("factorial of %d is %d \n",f,factorial(f));

  printf("setting %d th of %d is %d \n",k,num1,set(num1,k));
  printf("setting %d th of %d is %d \n",k,num1,clear(num1,k));
  printf("setting %d th of %d is %d \n",k,num1,flip(num1,k));



  return 0;
}
