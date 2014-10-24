# Make file for PA2
#
# This makefile is used as follows to regenerate files for the life program:


CFLAGS = -g

all: life 

life: Life.o Game.o Board.o
	gcc $(CFLAGS) -m32 -Wall Life.o Game.o Board.o -o life 

Life.o: Life.h Life.c
	gcc $(CFLAGS) -m32 -Wall -c Life.c

Game.o: Life.h Game.c
	gcc $(CFLAGS) -m32 -Wall -c Game.c
	
Board.o: Life.h Board.c
	gcc $(CFLAGS) -m32 -Wall -c Board.c
	
clean:
	rm -f Life.o Game.o Board.o life
