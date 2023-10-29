/* histogram_asm.asm 12.3.2015						*/
/* programmto calculate the histogram of a sequence of data. The data	*/
/* are stored in the array random and the number of data are given	*/
/* in the parameter size. The data itself has a range 0 - 255.		*/
/* The histogram is stored in the aray histogram.			*/
/* int histgram_asm(int size, int *random, int *histogram);		*/

	.global  histogram_asm	@ Program entry point


histogram_asm:
 	
	@ Please continue!

	mov PC,LR		@ back to the calling function
