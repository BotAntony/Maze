#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

int main(int argc, char** argv) {
    int x = 1, y = 1;
    int ch;

    // ncurses init
    initscr();
    noecho();
    cbreak();
    raw();
    curs_set(0);

    // draw a room
    int max_x, max_y;
    getmaxyx(stdscr, max_y, max_x);

    // draw the room
    for (int i = 0; i < max_y; ++i) {
        for (int j = 0; j < max_x; ++j) {
            if (i == 0 || i == max_y - 1 || j == 0 || j == max_x - 1) {
                mvaddch(i, j, '#');
            } else {
                mvaddch(i, j, '.');
            }
        }
    }

    // init the player
    mvaddch(y, x, '@');
    refresh();

    // game loop
    while ((ch = getch()) != 'q') {
        mvaddch(y, x, '.'); // clear previous position

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

        mvaddch(y, x, '@');
        refresh();
    }

    // end the ncurses library
    endwin();
    echo();
    curs_set(1);

    return 0;
}
