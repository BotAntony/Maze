#include "maze_gen.h"
#include "stack.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

// Define the neighbors constants array used in generateMaze()
const int neighbors_constants[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};

void printArray_debug(int rows, int cols, int array[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        printf("[");
        for (int j = 0; j < cols; ++j) {
            printf("%d, ", array[i][j]);
        }
        printf("]\n");
    }
}

void shuffle_array(int rows, int cols, int array[rows][cols]) {
#ifdef DEBUG_MAZE
    printf("Current array:\n");
    printArray_debug(rows, cols, array);
#endif
    for (int i = rows - 1; i > 0; --i) {
        int j = rand() % (i + 1);

        for (int k = 0; k < cols; k++) {
            int temp = array[i][k];
            array[i][k] = array[j][k];
            array[j][k] = temp;
        }
    }
#ifdef DEBUG_MAZE
    printf("Shuffled array:\n");
    printArray_debug(rows, cols, array);
#endif
}

void generateMaze(int **maze, int height, int width, int seed, int* finalCoords) {
    Stack stack;
    srand(seed);

    // Fill the maze with walls (1s)
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            maze[i][j] = 1;
        }
    }

    initialize_stack(&stack);
    push_stack(&stack, 0, 0);
    maze[0][0] = 0; // Starting point is a room (0)

    while (!isEmpty_stack(&stack)) {
        int x, y;
        x = peek_stack(&stack)[0];
        y = peek_stack(&stack)[1];

        // Define four possible directions and shuffle them
        int neighbors[4][2];
        for (int i = 0; i < 4; ++i) {
            neighbors[i][0] = x + neighbors_constants[i][0];
            neighbors[i][1] = y + neighbors_constants[i][1];
        }
        shuffle_array(4, 2, neighbors);

        for (int i = 0; i < 4; ++i) {
            int nx = neighbors[i][0];
            int ny = neighbors[i][1];

            // Check if neighbor is within bounds and a wall
            if ((0 <= nx && nx < width) && (0 <= ny && ny < height) && maze[ny][nx] == 1) {
                maze[(y + ny) / 2][(x + nx) / 2] = 0;
                maze[ny][nx] = 0;
                finalCoords[0] = x;
                finalCoords[1] = y;
                push_stack(&stack, nx, ny);
                break;
            }

            // Pop the stack if no unvisited neighbors remain
            if (i == 3) {
                pop_stack(&stack);
            }
        }
    }
}

void printMaze(int **maze, int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (maze[i][j] == 1) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

