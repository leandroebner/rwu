/* Function  vectrod.c 29.2.2016 					*/
/* Calculate the euclidian distance of to vectors			*/
/* The vectors has a maximal number of elements given im MAXDIM		*/
/* The actual dimension and the elements of the vectors are read in.	*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXDIM 32

extern int vectord_asm (int dimension, int *y1, int *y2);

int main()
{
  int i,dimension;
  int distance;
  int y1[MAXDIM],y2[MAXDIM];

  printf("The Dimension of the Vector is -> ");
  scanf("%d",&dimension);
  if (dimension > MAXDIM) dimension = MAXDIM;

  for (i=0;i<dimension;i++){
	printf("Y1_%d-> ",i);
	scanf("%d",&y1[i]);
  }

  printf("\n");

  for (i=0;i<dimension;i++){
	printf("Y2_%d-> ",i);
	scanf("%d",&y2[i]);
  }
  
  distance = vectord_asm (dimension,y1,y2);
  
  printf("The distances between the vectors is -> %d\n",distance);
  return 0;
}
