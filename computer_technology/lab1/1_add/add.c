/*
add.c 27.02.2016
Reads two integer from the keyboard
Passes these two values to the assembly program
 and prints out the sum */

#include <stdio.h>
#include <stdlib.h>

extern int addition_asm(int int_val1, int int_val2, int *result);

int int_val1, int_val2; 
int result, status; 

int main()
{
  printf("Please give the first Integer Value -> ");
  scanf("%d", &int_val1);

  printf("Please give the second Integer Value -> ");
  scanf("%d", &int_val2);  
     
  status = addition_asm(int_val1, int_val2, &result);	// calls the assembly program

  printf("The Sum is -> %d\n",result);
  printf("The status is -> %d\n",status);
  
  if (status !=0) printf("Assembler routine returned error: %d\n",status);
  else 	printf("The Sum is -> %d\n",result); 
 return 0;
}
