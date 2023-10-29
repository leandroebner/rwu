/* Functionname ascii2int_asm (char *source, int *result);				*/
/* Function: Convert a ascii-string with numeric characters in a int. The string can	*/
/* start with a sign (+ or -). Alpha-characters are not allowed, in this case the 	*/
/* function gives a -1 back.								*/
/* Parameter: 	source pointer to ascii-string						*/
/* 		result pointer to integer 						*/


	.global ascii2int_asm			@ Programm Entry Point

ascii2int_asm:
	
	@ Please continue!

	mov PC,LR

.data

