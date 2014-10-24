/*
 * Life.c
 *
 *      Author: Alex Shoop
 *      For CS 2303 PA2
 */

/*
 * print out only final board in final program.
 * and it'd be good to say "how many gens" or stuff like that
 */

/*
 * grid can be 1 and 0
 * input file is x and o
 */

#include <stdio.h>
#include <stdlib.h>
#include "Life.h"

FILE *input;
int x,y,gens;
char print, pause;

int main (int argc, char *argv[]) {
	int **currentBoard, **prevBoard, **nextBoard;
	int i;
	int genCounter = 1;

	if (argc < 5) {
		printf("Error. Please type all input arguments.\n");
		return 0;
	}

	// size of x-coordinate of grid
	x = atoi(argv[1]);
	// size of y-coordinate of grid
	y = atoi(argv[2]);
	// number of requested generations
	gens = atoi(argv[3]);
	// input file
	input = fopen(argv[4], "r");
	if (!input) {
		printf("Error. Unable to open file. Please try again.\n");
		return 0;
	}
	// print all generations or not
	print = 'n';
	if (argc >= 6) {
	print = *argv[5];
	}
	// pause at each generation or not
	pause = 'n';
	if (argc > 6) {
	pause = *argv[6];
	}

	// sets up currentBoard
	currentBoard = malloc(x * sizeof(int *));
	if (currentBoard) for (i = 0; i < x; i++) {
		currentBoard[i] = malloc(y * sizeof(int));
		if (!currentBoard[i]) exit (-1);
	}

	// sets up prevBoard
	prevBoard = malloc(x * sizeof(int *));
	if (prevBoard) for (i = 0; i < x; i++) {
		prevBoard[i] = malloc(y * sizeof(int));
		if (!prevBoard[i]) exit (-1);
	}

	// sets up nextBoard
	nextBoard = malloc(x * sizeof(int *));
	if (nextBoard) for (i = 0; i < x; i++) {
		nextBoard[i] = malloc(y * sizeof(int));
		if (!nextBoard[i]) exit (-1);
	}

	// puts input file into board.
	// BOARD GRID SIZE AND FILE GRID SIZE MUST BE SAME
	putFileInBoard(input, currentBoard, x, y);

	// sets nextBoard to the played game from currentBoard
	nextBoard = playOne(x, y, currentBoard);

	// sets prevBoard to NULL
	prevBoard = NULL;

	int E = endCondition(currentBoard, prevBoard, nextBoard, x, y, genCounter, gens);

	printf("Original board:\n");
	printBoard(currentBoard, x, y);
	printf("\n");

	while (E != 1) {
		if (print == 'y') {
			printBoard(nextBoard, x, y);
			printf("\n");
			if (pause == 'y') {
				printf("PRESS ANY KEY\n");
				getc(stdin);
			}
		}
		free(prevBoard);
		genCounter++;
		prevBoard = currentBoard;
		currentBoard = nextBoard;
		nextBoard = playOne(x, y, currentBoard);
		E = endCondition(currentBoard, prevBoard, nextBoard, x, y, genCounter, gens);
	}

	printf("This is the last generation.\n");
	printBoard(currentBoard, x, y);
	printf("Program has reached %d generations.\n", genCounter - 1);

	free(currentBoard);
	free(nextBoard);
	free(prevBoard);
	fclose(input);
	return 0;
}	// int main
