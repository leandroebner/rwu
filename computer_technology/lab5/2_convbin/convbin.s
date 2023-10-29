.global  convbin_s	@ Program Entry Point

convbin_s:

  @Please Continue
  
	mov R0, #0
	mov PC,LR		@ back to the calling function

Fehler:

	mov R0, #-1
	mov PC,LR

.data

