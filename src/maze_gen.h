#ifndef MAZE_GEN_H_
#define MAZE_GEN_H_

#include <stdlib.h>
#include <stdio.h>

// Define DEBUG mode
// #define DEBUG_MAZE 1

// Constant for neighbors used in generateMaze()
extern const int neighbors_constants[4][2];

void printArray_debug(int rows, int cols, int array[rows][cols]);
void shuffle_array(int rows, int cols, int array[rows][cols]);
void generateMaze(int **maze, int height, int width, int seed, int* finalCoords);
void printMaze(int **maze, int height, int width, int finalCoords[2]);

#endif
