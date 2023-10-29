/* Function strcpy.c 27.2.2016							*/
/* Function to copy parts of string. The string itself is passed by a pointer.	*/
/* The start of the copied part and the length  by the parameter start and num.	*/
/* The copied part are stored under the address dest.				*/


#include <stdio.h>
#include <stdlib.h>


extern int asmcpy(char *source, char *dest, int start, int num);

char source[256],dest[256];


int main()
{
  int start,num, status;

  printf("Please write the String: ");
  fgets(source, 256, stdin);

  printf("Start : ");
  scanf("%d", &start);

  printf("Number of Elements : ");
  scanf("%d", &num);

  status = asmcpy(source,dest,start,num);

    if (status !=0){
       printf("Assembler routine returned error: %d\n",status);
    }

    printf("The copied String is: %s\n",dest);

  return 0;
}
