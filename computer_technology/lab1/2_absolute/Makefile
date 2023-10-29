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

all: Absolute

Absolute : absolute.o absolute_asm.o 
	$(CC) $(CFLAGS) -o Absolute absolute.o absolute_asm.o


absolute_asm.o : absolute_asm.asm


absolute.o : absolute.c


clean :
	rm *.o
	rm *.lst
	rm Absolute
debug :
	gdb ./Absolute -x gdb_command

