/*
 * Board.c
 *
 *      Author: Alex Shoop
 *      For CS 2303 PA2
 */


#include <stdio.h>
#include "Life.h"

// prints out the board
void printBoard (int **B, unsigned int x, unsigned int y) {
	int j, k;
	for (j = 0; j < x; j++) {
		for (k = 0; k < y; k++) {
			printf("%d", B[j][k]);
		}
		printf("\n");
	}
}	// void printBoard

int countNearestNeighbor (int **Board, unsigned int sizeX, unsigned int sizeY, unsigned int x, unsigned int y) {
	int counter = 0;

	/*
	 count(B, sizeX, sizeY, x, y)
	int neighbors = 0;
	int i,j;
	for (i = x-1; i <= x+1; i++) {
		for (j = y-1; j <= y+1; j++) {
			if (i >= 0 && i < sizeX && j >= 0 && j < sizeY) {
				neighbors += Board[i][j];
				if(i==x && j==y) {
					neighbors = neighbors - 1;
				}
			}
		}
	}
	return neighbors;
	*/

	// at the first element space (ie top left)
	if (x == 0 && y == 0) {
		if (Board[x][y+1] == 1) {
			counter++;
		}
		if (Board[x+1][y+1] == 1) {
			counter++;
		}
		if (Board[x+1][y] == 1) {
			counter++;
		}
	}
	// at the last element space (ie bottom right)
	else if (x == (sizeX - 1) && y == (sizeY - 1)) {
		if (Board[x][y-1] == 1) {
			counter++;
		}
		if (Board[x-1][y-1] == 1) {
			counter++;
		}
		if (Board[x-1][y] == 1) {
			counter++;
		}
	}
	// at element space top right
	else if (x == 0 && y == (sizeY - 1)) {
		if (Board[x+1][y] == 1) {
			counter++;
		}
		if (Board[x+1][y-1] == 1) {
			counter++;
		}
		if (Board[x][y-1] == 1) {
			counter++;
		}
	}
	// at element space bottom left
	else if (x == (sizeX - 1) && y == 0) {
		if (Board[x-1][y] == 1) {
			counter++;
		}
		if (Board[x-1][y+1] == 1) {
			counter++;
		}
		if (Board[x][y+1] == 1) {
			counter++;
		}
	}
	// at any element in top-most row
	else if (x == 0 && y < (sizeY - 1)) {
		if (Board[x][y-1] == 1) {
			counter++;
		}
		if (Board[x+1][y-1] == 1) {
			counter++;
		}
		if (Board[x+1][y] == 1) {
			counter++;
		}
		if (Board[x+1][y+1] == 1) {
			counter++;
		}
		if (Board[x][y+1] == 1) {
			counter++;
		}
	}
	// at any element in right-most column
	else if (x < (sizeX - 1) && y == (sizeY - 1)) {
		if (Board[x-1][y] == 1) {
			counter++;
		}
		if (Board[x-1][y-1] == 1) {
			counter++;
		}
		if (Board[x][y-1] == 1) {
			counter++;
		}
		if (Board[x+1][y-1] == 1) {
			counter++;
		}
		if (Board[x+1][y] == 1) {
			counter++;
		}
	}
	// at any element bottom-most row
	else if (x == (sizeX - 1) && y < (sizeY - 1)) {
		if (Board[x][y-1] == 1) {
			counter++;
		}
		if (Board[x-1][y-1] == 1) {
			counter++;
		}
		if (Board[x-1][y] == 1) {
			counter++;
		}
		if (Board[x-1][y+1] == 1) {
			counter++;
		}
		if (Board[x][y+1] == 1) {
			counter++;
		}
	}
	// at any element left-most column
	else if (x < (sizeX - 1) && y == 0) {
		if (Board[x-1][y] == 1) {
			counter++;
		}
		if (Board[x-1][y+1] == 1) {
			counter++;
		}
		if (Board[x][y+1] == 1) {
			counter++;
		}
		if (Board[x+1][y+1] == 1) {
			counter++;
		}
		if (Board[x+1][y] == 1) {
			counter++;
		}
	}
	// at any element space not in above conditions
	else if (x < (sizeX - 1) && y < (sizeY - 1)) {
		if (Board[x-1][y-1] == 1) {
			counter++;
		}
		if (Board[x-1][y] == 1) {
			counter++;
		}
		if (Board[x-1][y+1] == 1) {
			counter++;
		}
		if (Board[x][y-1] == 1) {
			counter++;
		}
		if (Board[x][y+1] == 1) {
			counter++;
		}
		if (Board[x+1][y-1] == 1) {
			counter++;
		}
		if (Board[x+1][y] == 1) {
			counter++;
		}
		if (Board[x+1][y+1] == 1) {
			counter++;
		}
	}
	return counter;
} // int checkNearestNeighbor

