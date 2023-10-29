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

all: Histogram

Histogram : histogram.o histogram_asm.o 
	$(CC) $(CFLAGS) -o Histogram histogram.o histogram_asm.o


histogram_asm.o : histogram_asm.asm


histopgram.o : histogram.c


clean :
	rm *.o
	rm *.lst
	rm Histogram

debug :
	gdb ./Histogram -x gdb_command

