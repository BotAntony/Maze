#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

typedef enum {
    EMPTY,
    WALL,
    PLAYER,
} Cell;

void drawRoom(Cell** room, int height, int width) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            switch (room[i][j]) {
                case WALL:
                    mvaddch(i, j, '#');
                    break;
                case PLAYER:
                    mvaddch(i, j, '@');
                    break;
                case EMPTY:
                default:
                    mvaddch(i, j, '.');
            }
        }
    }
    refresh();
}

int returnError(char* error) {
    // end the ncurses library
    endwin();
    echo();
    curs_set(1);
    printf("Error: %s", error);
    return -1;
}

int main(int argc, char** argv) {
    int x = 1, y = 1;
    int ch;
    Cell** room;
    int _temp_max_x, _temp_max_y;

    // ncurses init
    initscr();
    noecho();
    cbreak();
    raw();
    curs_set(0);

    // define room size
    getmaxyx(stdscr, _temp_max_y, _temp_max_x);
    const int max_x = _temp_max_x, max_y = _temp_max_y;

    // allocate memory
    room = (Cell**)malloc(max_y * sizeof(Cell*));
    for (int i = 0; i < max_y; ++i) {
        room[i] = (Cell*)malloc(max_x * sizeof(Cell));
    }

    // fill the cells
    for (int i = 0; i < max_y; ++i) {
        for (int j = 0; j < max_x; ++j) {
            if (i == 0 || i == max_y - 1 || j == 0 || j == max_x - 1) {
                room[i][j] = WALL;
            } else {
                room[i][j] = EMPTY;
            }
        }
    }

    // init the player
    room[y][x] = PLAYER;
    drawRoom(room, max_y, max_x);

    // game loop
    while ((ch = getch()) != 'q') {
        // return error if the resolution is less than the initial one
        getmaxyx(stdscr, _temp_max_y, _temp_max_x);
        if (_temp_max_x < max_x || _temp_max_y < max_y) {
            return returnError("the current resolution is smaller than the initial one!");
        }

        room[y][x] = EMPTY; // clear previous position

        switch (ch) {
            case 'w':
            case KEY_UP:
                if (y > 2) y -= 2;
                else if (y > 1) --y;
                break;
            case 's':
            case KEY_DOWN:
                if (y < max_y - 3) y += 2;
                else if (y < max_y - 2) ++y;
                break;
            case 'a':
            case KEY_LEFT:
                if (x > 2) x -= 2;
                else if (x > 1) --x;
                break;
            case 'd':
            case KEY_RIGHT:
                if (x < max_x - 3) x += 2;
                else if (x < max_x - 2) ++x;
                break;
        }

        room[y][x] = PLAYER;
        drawRoom(room, max_y, max_x);
    }

    // free memory
    for (int i = 0; i < max_y; ++i) {
        free(room[i]);
    }
    free(room);

    // end the ncurses library
    endwin();
    echo();
    curs_set(1);

    return 0;
}
