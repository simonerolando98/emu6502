OBJS	= emu6502/src/core.o emu6502/src/main.o
SOURCE	= emu6502/src/core.c emu6502/src/main.c
HEADER	= emu6502/include/core.h emu6502/include/opcodes.h
OUT	= emu6502_prg
CC	 = gcc
FLAGS	 = -g -c -Wall -O0
LFLAGS	 = -lm

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

emu6502/src/core.o: emu6502/src/core.c
	$(CC) $(FLAGS) emu6502/src/core.c -std=c11 -o emu6502/src/core.o

emu6502/src/main.o: emu6502/src/main.c
	$(CC) $(FLAGS) emu6502/src/main.c -std=c11 -o emu6502/src/main.o


clean:
	rm -f $(OBJS) $(OUT)