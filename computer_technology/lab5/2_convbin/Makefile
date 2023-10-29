.SUFFIXES: .o .asm .c

AS=as
ASFLAGS= -g
CFLAGS= -g 
CC=gcc

FILE= convbin

# All Targets
all: $(FILE)

# Executable depends on the files .c.o and .s.o.
$(FILE): $(FILE).c.o $(FILE).s.o
	gcc $(CFLAGS) -o $(FILE) $(FILE).c.o $(FILE).s.o

# Depends on the source
$(FILE).c.o: $(FILE).c
	gcc $(CFLAGS) -c -o $(FILE).c.o $(FILE).c 
 
$(FILE).s.o: $(FILE).s
	$(AS) $(ASFLAGS) -o $(FILE).s.o $(FILE).s

#tell make that "clean" is not a file name!
.PHONY: clean debug

#Clean the build directory
clean: 
	rm -f *.o $(FILE)

debug:
	nemiver $(FILE)
