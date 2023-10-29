/* Functionname Stringcpy_asm (char *source, char *dest, int start, int num);		*/
/* Function: Copied a String form source to dest. The beginning is updated with		*/
/* start and the number of character which should copied is given in number.		*/
/* Parameter: 	source pointer to source						*/
/* 		dest pointer to destination						*/
/*		start beginning of the string which have to be copied 			*/
/*		number number of character which have to be copied			*/


	.global asmcpy				@ Programm Entry Point

asmcpy:
	
	@ Please continue!

        mov PC,LR                               @ back to the calling function

.data

