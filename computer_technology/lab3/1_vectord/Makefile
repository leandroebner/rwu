#
# Linux makefile
# Use with make 
#


.SUFFIXES: .o .asm .c

AS=as
ASFLAGS= -mcpu=cortex-a7 -mfpu=neon -g -o 
CFLAGS= -g
CC=gcc

.asm.o:
	$(AS) $(ASFLAGS) $*.o $*.asm -al=$*.lst 

.c.o:
	$(CC) -c $(CFLAGS) $*.c

all: Vector

Vector : vectord.o vectord_asm.o 
	$(CC) $(CFLAGS) -o Vector vectord.o vectord_asm.o -lm


vectord_ass.o : vectord_asm.asm


vectord.o : vectord.c


clean :
	rm *.o
	rm *.lst
	rm Vector

debug :
	gdb ./Vector -x gdb_command

