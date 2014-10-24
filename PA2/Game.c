/*
 * Game.c
 *
 *      Author: Alex Shoop
 *      For CS 2303 PA2
 */

/*
 * ./life args args args > file.txt
 * this creates the stdout file
 */

#include <stdio.h>
#include <stdlib.h>
#include "Life.h"

// plays one game, by creating a new array from the old array
int **playOne (unsigned int x, unsigned int y, int **Old) {
	unsigned int i,j, temp;
	int **New = malloc(x * sizeof(int *));
	if (New) for (i = 0; i < x; i++) {
		New[i] = malloc(y * sizeof(int));
	}

	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			temp = countNearestNeighbor(Old, x, y, i, j);
			// inside occupied cell
			if (Old[i][j] == 1) {
				// if neighbors are 0, 1, or 4 to 8
				if (temp < 2 || temp > 3) {
					New[i][j] = 0;
				}
				// if neighbors are 2 or 3
				else if (temp == 2 || temp == 3) {
					New[i][j] = Old[i][j];
				}
			}
			// inside unoccupied cell
			else if (Old[i][j] == 0) {
				if (temp == 3) {
					New[i][j] = 1;
				}
			}
		}
	}
	return New;
}	// int playOne

// compares two boards and returns 1 if not same or 0 if is same
int compareBoards (int **A, int **B, unsigned int sizeX, unsigned int sizeY) {
	unsigned int i,j;
	if (A == NULL || B == NULL) {
		return 1;
	}
	for (i = 0; i < sizeX; i++) {
		for (j = 0; j < sizeY; j++) {
			if (A[i][j] != B[i][j]) {
				return 1;
			}
		}
	}
	return 0;
} // int compareBoards

// check if board has all dead cells. Return 1 if not all are dead, or 0 if all are dead
int allDead(int **A, int x, int y) {
	int i, j;
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++) {
			if (A[i][j] == 1) {
				return 1;
			}
		}
	}
	return 0;
}

// the end condition on whether the same pattern has been retrieved,
// whether the entire board has no cells,
// or whether the requested number of generations has been reached
int endCondition(int **A, int **B, int **C, int x, int y, int genCounter, int gens) {
	if (compareBoards(A, B, x, y) == 0 || compareBoards(B, C, x, y) == 0) {
		printf("Program has reached same pattern.\n");
		return 1;
	}

	if (allDead(A, x, y) == 0) {
		printf("No more living cells in board.\n");
		return 1;
	}

	if (genCounter > gens) {
		printf("Program has reached number of requested generations.\n");
		return 1;
	}
	return 0;
}	// int endCondition

// puts the input file in the Board
void putFileInBoard(FILE *file, int **B, unsigned int sizeX, unsigned int sizeY) {
	int i, j;
	char c;
	for (i = 0; i < sizeX; i++) {
		for (j = 0; j < sizeY; j++) {
			c = fgetc(file);
			while (c != 'x' && c != 'o' && c != EOF) {
				c = fgetc(file);
			}
			if (c == 'x' && c != EOF) {
				B[i][j] = 1;
			}
			else if (c == 'o' && c != EOF) {
				B[i][j] = 0;
			}
			else if (c == EOF) {
				printf("Error. Please have grid size and input file size the same\n");
				exit (-1);
			}
		}
	}
}	// void putFileInBoard

