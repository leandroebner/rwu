/*
 * file: Matrix_Add.c
 * Programm zur Addition zweier Matrizen. Die Matrizenelemente sind vom Typ 'short.
 * Die Matrizen werden in einer Datenstruktur beschrieben, (siehe strct Matrix), in der
 * die Anzahl der Spalten und Zeilen sowie die maximale Anzahl der Spalten angegeben
 * sind. Durch diese Angaben können Matrizen unterschiedlicher Größe, bis zur
 * Maximalgröße von 10 x 10 Elementen spezifizeirt werden. Des weiteren bietet
 * die Definition der Struktur die Möglichkeit eine Funktion mit sehr wenigen
 * Parametern aufzurufen.
 */

#include <stdio.h>
#include <stdlib.h>


struct Matrix{
  int row;
  int maxcolumn;
  int column;
  int mat[10][10];
  };



/*
 * function Ass_Matrix
 * Add two matrixes; the number of rows and columns have to be the same
 * The matrixes  are organized in the datatype Struct "Matrix"
 *
 * 	struct Matrix{
 * 	  unsigned short row;
 * 	  unsigned short maxrow;
 * 	  unsigned short column;
 *	  unsigned short mat[10][10];
 * 	  };
 *
 * The elements of the matrixes are signed 16 Bit numbers
 * Parameters:
 *   a - 1. matrix
 *   b - 2. matrix
 *   sum -> Destination -> Sum of a + b
 */
extern int matrixAdd_s( struct Matrix *A, struct Matrix *B, struct Matrix *Sum ) ;

struct Matrix Matrix_A, Matrix_B, Matrix_Sum;

int main()
{
  int status;
  int i,j;

  int row, column;

  printf("Bitte geben Sie die Anzahl von Zeilen (max. 10) und Spalten (max. 10) Ihrer Matrix an!\n");
  printf("Anzahl von Zeilen? --> ");
  scanf("%d", &row);
  if (row > 10) row = 10;	/* Limitation of rows */
  printf("Anzahl von Spalten? --> ");
  scanf("%d", &column);
  if (column > 10) column = 10;	/* Limitation of columns */
  Matrix_A.row = Matrix_B.row = Matrix_Sum.row = row;
  Matrix_A.maxcolumn = Matrix_B.maxcolumn = Matrix_Sum.maxcolumn = 10;
  Matrix_A.column = Matrix_B.column = Matrix_Sum.column = column;

  for (i = 0; i < row; i++)
    for (j = 0; j < column; j++){
      printf("Matrix_A[%d],[%d] ", i, j);
      scanf("%hd",&Matrix_A.mat[i][j]);
    }

  printf("\n\n");

  for (i = 0; i < row; i++)
    for (j = 0; j < column; j++){
      printf("Matrix_B[%d],[%d] ", i, j);
      scanf("%d",&Matrix_B.mat[i][j]);
    }

  status = matrixAdd_s(&Matrix_A, &Matrix_B, &Matrix_Sum);

    /*
     * print out the result
     */

  if (status !=0) {
	printf("Assembler routine returned error: %d\n",status);
  return status;
  }
  
  else printf("Die Summe ist:\n");

  for (i = 0; i < row; i++){
    for (j = 0; j < column; j++){
      printf("Matrix_Sum[%d],[%d] ", i, j);
      printf("%d ",Matrix_Sum.mat[i][j]);
    }
    printf("\n");
  }

    status = 0;


  return status;
}
