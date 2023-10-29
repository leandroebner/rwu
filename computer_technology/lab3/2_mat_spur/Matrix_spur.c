/*
 * file: Matrix_Add.c
 * Program for a matrix Spur. The elements of the matrixes are type 'int'.
 * The matrixes are described in a data structure (struct matrix). 
 * The structure contents in addition to the matrix elements the number of rows,
 * the number of columns and the max number of columns of the matrix.
 * With the help of this parameters there can be specified matrixes with a different
 * number of elements (max 10 x10 elements).
 * Because of the definition of a structure a function call can be realized 
 * with only a few parameters.
 */

#include <stdio.h>
#include <stdlib.h>

struct Matrix{
  unsigned int row;
  unsigned int maxcolumn;
  unsigned int column;
  int mat[10][10];
  };

extern int Ass_Matrix( struct Matrix *A, int *spur);

struct Matrix Matrix_A;

int main()
{
  int status;
  int i,j,spur;

  unsigned int row, column;

  printf("Please specify the number of rows (max 10) and columns (max 10) of the matrix!\n");
  printf("Number of rows? --> ");
  scanf("%d", &row);
  if (row > 10) row = 10;	/* Limitation of rows */
  Matrix_A.row =row;
  printf("Number of columns? --> ");
  scanf("%d", &column);
  if (column > 10) column = 10;	/* Limitation of columns */
  Matrix_A.column =column;

  for (i = 0; i < row; i++) {
    for (j = 0; j < column; j++){
      printf("Matrix_A[%u],[%u] ", i, j);
      scanf("%d",&Matrix_A.mat[i][j]);
    }
   } 

  Matrix_A.maxcolumn = 10;

  status = Ass_Matrix(&Matrix_A, &spur);

  if (status!=0){
      	printf("Assembly Program returned error code: %d\n",status);
	return status;
  }
  else{
  printf("\nThe Trace Value (Spur) is: %d\n",spur);
  return 0;
  }
}
