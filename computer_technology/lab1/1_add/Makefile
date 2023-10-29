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

all: Add

Add : add.o add_asm.o 
	$(CC) $(CFLAGS) -o Add add.o add_asm.o


add_asm.o : add_asm.asm


add.o : add.c


clean :
	rm *.o
	rm *.lst
	rm Add

debug :
	gdb ./Add -x gdb_command

