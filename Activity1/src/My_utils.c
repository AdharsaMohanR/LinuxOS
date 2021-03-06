#include "My_utils.h"
int factorial(int n)
{
  if (n == 0) 
    return 1;
  else
    return (n*factorial(n-1));
}

int isPrime(int k)
{
   int c;
 
   for ( c = 2 ; c <= k - 1 ; c++ )
   { 
      if ( k%c == 0 )
     return 0;
   }
   return 1;
}
 

int ispalindrome(int n){
    int r,s=0,tmp;
    tmp=n;
    while(n>0)    
    {    
        r=n%10;    
        s=(s*10)+r;    
        n=n/10;    
    }    
    if(tmp==s)    
       return 1; 
    else     
       return 0;  

}
