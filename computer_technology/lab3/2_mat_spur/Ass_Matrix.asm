/* Programm Ass_Matrix 29.2.2016					*/
/* Program for the Spur of a matrix. The structure of the matrix is 	*/
/* defined in a c-program by the datatype 'struct'. Parameter of the 	*/
/* program are two pointers. The first pointer points to the structure.	*/
/* The second pointer points to memory location where the result should	*/
/* stored. The function value						*/ 
/* describes an error code with the following meaning:			*/
/*									*/
/* Return value = 0 -> everything all right				*/
/* Return value =-1 -> fatal error (matrixes do not fit)		*/

/*									*/
/* function Ass_Matrix							*/
/* Spur of a matrix; (must be quadratic)				*/
/* The matrix is organized in the datatype struct "matrix"		*/
/*									*/
/* 	typedef struct{							*/
/* 	  unsigned int row;						*/
/* 	  unsigned int maxcolumn;					*/
/* 	  unsigned int column;						*/
/*	      int mat[10][10];						*/
/* 	  } matrix;							*/
/*									*/


        .global  Ass_Matrix

Ass_Matrix:
        
	@ Please continue!

	mov PC,LR




