#
# Linux makefile
# Use with make 
#

.SUFFIXES: .o .asm .c

AS=as
ASFLAGS= -g -o
CFLAGS= -g 
CC=gcc


.asm.o:
	$(AS) $(ASFLAGS) $*.o $*.asm -al=$*.lst


.c.o:
	$(CC) -c $(CFLAGS) $*.c

all: Spur

Spur : Ass_Matrix.o Matrix_spur.o 
	$(CC) $(CFLAGS) -o Spur Ass_Matrix.o Matrix_spur.o


Ass_Matrix.o : Ass_Matrix.asm


Matrix_spur.o : Matrix_spur.c


clean :
	rm *.o
	rm *.lst
	rm Spur

debug :
	gdb ./Spur -x gdb_command

