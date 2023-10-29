/* Function asciito.c 29.2.2016							*/
/* Function to convert a ascii string given by a commandline parameter	to 	*/
/* an integer. The string is passed by a pointer and the result are passed	*
/* as a pointer to an int.							*/
/* The function gives a -1 back if the ascii string contains alpha characters.	*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int ascii2int_asm(char *ascii, int *result);


int main(int argc, char **argv)
{
  int result, status;

  if(argc != 2){
     printf("Usage: Ascci2int ascii-string\n");
     return -1;
  }

  status = ascii2int_asm(argv[1], &result);

  if (status !=0){
     printf("Assembler routine returned error: %d\n",status);
     return -1;
  }

  printf("First parameter is %s\n",argv[1]);

  printf("The Integer Value in decimal notation is : %d and in hexadecimal notation : %X \n",result, result);

  return 0;
}

