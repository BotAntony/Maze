#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "maze_gen.h"

#define HEIGHT_CONST 10
#define WIDTH_CONST 10

// #define DEBUG_MAIN 1

int main(int argc, char* argv[]) {
    int height = HEIGHT_CONST;
    int width = WIDTH_CONST;
    int seed = (int)time(NULL);
    char param;

    // process args
    for (int i = 1; i < argc; ++i) {
        if (argv[i][0] == '-') {
            param = argv[i][1];
#ifdef DEBUG_MAIN
            printf("Param: %c\n", param);
            if (i + i < argc) {
                printf("Num: %d\n", atoi(argv[++i]));
            }
#else
            if (i + 1 < argc) {
                switch (param) {
                    case 'r':
                        height = atoi(argv[++i]);
                        if (height < 4 || height > 64) {
                            height = HEIGHT_CONST;
                        }
                        break;
                    case 'c':
                        width = atoi(argv[++i]);
                        if (width < 4 || width > 64) {
                            width = WIDTH_CONST;
                        }
                        break;
                    case 's':
                        seed = atoi(argv[++i]);
                        break;
                    default:
                        printf("Error: unknown parameter!\n");
                        break;
                }
            } else {
                if (param == 'h') {
                    printf("This program generates a maze using DFS algorithm.\n\n");
                    printf("Usage:\n    maze [options]\n\n");
                    printf("Options:\n");
                    printf("    -c <cols>     Set the amount of columns (10 by defualt, range 4-64)\n");
                    printf("    -r <rows>     Set the amount of rows (10 by default, range 4-64)\n");
                    printf("    -s <seed>     Set a seed (time() by default, an integer value)\n");
                    printf("    -h <help>     Display this page, do not print the maze\n");
                    return 0;
                }
                if (!(param == 's' || param == 'c' || param == 'r')) {
                    printf("Error: unknown parameter -%c!\n", param);
                } else {
                    printf("Error: parameter -%c requires a value!\n", param);
                }
            }
#endif
        }
    }

    // allocate memory
    int **maze = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; ++i) {
        maze[i] = (int *)malloc(width * sizeof(int));
    }
    int finalCoords[2];
    generateMaze(maze, height, width, seed, finalCoords);
    printMaze(maze, height, width, finalCoords);
    // free memory
    for (int i = 0; i < height; ++i) {
        free(maze[i]);
    }
    free(maze);
    return 0;
}
