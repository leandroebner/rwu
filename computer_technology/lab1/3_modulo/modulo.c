/*
modulo.c 27.2.2012
Reads 2 integer values from the keyboard
Passes these two integers to the function and get the quotient and the modulo value back
In case a divisor = 0 is transfered the function gives a -1 back.
*/

#include <stdio.h>
#include <stdlib.h>


extern int modulo_asm ( int dividend, int divisor ,int *quozient, int *modulo);

int main()
{
  unsigned int divisor,dividend,quozient,modulo;
  int error;	

  printf("Please give the Divident -> ");
  scanf("%u", &dividend);
  
  if(dividend >= 0x7fffffff){
	printf("Please give an unsigned Number\n");
	return -1;
  };
  printf("and the divisor -> ");
  scanf("%u", &divisor);
  if(divisor >= 0x7fffffff){
	printf("Please give an unsigned Number\n");
	return -1;
  };

  error = modulo_asm (dividend, divisor, &quozient, &modulo);	// calls the assembly program

  if(error == -1) printf("Error! Divisor is 0! \n"); else printf("Quozient is -> %d and Modulo is -> %d\n",quozient, modulo);

  return 0;
}
