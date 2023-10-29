/* add_asm.asm 6.3.2018						*/
/* Add two integer values int_value1, int_value2 passed by the 	*/
/* calling c program and gives the sum back.				*/
/* The sum have to be transfered in the R0.				*/
/*									*/
/* int addition_asm ( int int_val1, int_val2);	*/


        .global  addition_asm	@ Program Entry Point

addition_asm:

  @Please Continue
  
	mov R0, #0
	mov PC,LR		@ back to the calling function

Fehler:

	mov R0, #-1
	mov PC,LR

.data
