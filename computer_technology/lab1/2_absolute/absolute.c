/*
absolute.c 27.02.2016
read integer value from the keyboard
pass integers, and a int pointer
to the assembly routine absolute
*/

#include <stdio.h>
#include <stdlib.h>

extern int  absolute_asm ( int a, int *result);

int main()
{
  int status,a,result;	  

  printf("Please give an Integer-Value -> ");
  scanf("%d", &a);

  status = absolute_asm (a,&result);

  if (status !=0) printf("Assembler routine returned error: %d\n",status);
  else 	printf("The absolute value is -> %d\n",result);

  return status;
}
