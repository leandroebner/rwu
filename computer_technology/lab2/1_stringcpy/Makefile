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

all: Stringcpy

Stringcpy : Stringcpy.o Stringcpy_asm.o 
	$(CC) $(CFLAGS) -o Stringcpy Stringcpy.o Stringcpy_asm.o


Stringcpy_asm.o : Stringcpy_asm.asm


Stringcpy.o : Stringcpy.c


clean :
	rm *.o
	rm *.lst
	rm Stringcpy

debug :
	gdb ./Stringcpy -x gdb_command

