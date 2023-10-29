@Program for a matrix addition. The structure of the matrixes is defined
@in a c-program by the datatype 'struct'. Parameter of the program are three
@pointers to three of the described structures. The function value 
@;describes an error code with the following meaning:

@Return value = 0 -> everything all right
@Return value =-1 -> fatal error (matrixes do not fit)

        .global  matrixAdd_s	@ Program Entry Point

matrixAdd_s:

  @Please Continue
  
	mov R0, #0
	mov PC,LR		@ back to the calling function

Fehler:

	mov R0, #-1
	mov PC,LR

.data

