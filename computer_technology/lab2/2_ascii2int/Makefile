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

all: Ascii2int

Ascii2int : ascii2int.o ascii2int_asm.o 
	$(CC) $(CFLAGS) -o Ascii2int ascii2int.o ascii2int_asm.o


ascii2int_asm.o : ascii2int_asm.asm


ascii2int.o : ascii2int.c


clean :
	rm *.o
	rm *.lst
	rm Ascii2int

debug :
	gdb ./Ascii2int 123 -x gdb_command

