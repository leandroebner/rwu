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

all: Modulo

Modulo : modulo.o modulo_asm.o 
	$(CC) $(CFLAGS) -o Modulo modulo.o modulo_asm.o


modulo_asm.o : modulo_asm.asm


modulo.o : modulo.c


clean :
	rm *.o
	rm *.lst
	rm Modulo
debug :
	gdb ./Modulo -x gdb_command

