 /* file: histogram.c 12.3.2015
  * The histogram data are written into an output file
  * (./Plot.dat) in the current folder. */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000000

extern int histogram_asm (int size, int *random, int *histogram);

int main()
{
  int i,size,start_int,status,mean;
  int histogram[256],random[MAXSIZE];
  
  FILE *plot;
 
  printf("Number of elements to be generated: ");

  scanf("%d",&size);
  if (size>MAXSIZE) size=MAXSIZE;

  for (i = 0; i < size; i++) {
             random[i] = rand() % 256; 
        }
  
  status = histogram_asm (size, &random[0], &histogram[0]); //call the assembly program 

  
  if (status !=0) {
	printf("Assembler routine returned error: %d\n",status);
  	}
  else{  
        printf("Creating file Plot.dat \n");
        plot = fopen("./Plot.dat","w");	/* Create and open Plot.dat */
        for (i = 0; i < 256; i++){
              fprintf(plot, "%d %d \n", i, histogram[i]);
        }
        fclose(plot);
	
  }

  return status;
}
