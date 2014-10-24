/*
 * Life.h
 *
 *      Author: Alex Shoop
 *      For CS 2303 PA2
 */


void printBoard(int **B, unsigned int x, unsigned int y);
int countNearestNeighbor (int **Board, unsigned int sizeX, unsigned int sizeY, unsigned int x, unsigned int y);
int **playOne(unsigned int x, unsigned int y, int **Old);
int compareBoards (int **A, int **B, unsigned int sizeX, unsigned int sizeY);
void putFileInBoard(FILE *file, int **B, unsigned int sizeX, unsigned int sizeY);
int getFileGridX(FILE *file);
int getFileGridY(FILE *file);
int endCondition(int **A, int **B, int **C, int x, int y, int genCounter, int gens);
int allDead(int **A, int x, int y);

