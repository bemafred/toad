
#include <stdlib.h>
#include <curses.h>
#include <signal.h>

static void finish(int sig);

int main(int argc, char *argv[])
{
    int num = 0;

    /* initialize your non-curses data structures here */

    (void)signal(SIGINT, finish); /* arrange interrupts to terminate */

    (void)initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE); /* enable keyboard mapping */
    (void)nonl();         /* tell curses not to do NL->CR/NL on output */
    (void)cbreak();       /* take input chars one at a time, no wait for \n */
    //(void) echo();         /* echo input - in color */
    (void)noecho();

    if (has_colors())
    {
        start_color();

        /*
         * Simple color assignment, often all we need.  Color pair 0 cannot
         * be redefined.  This example uses the same value for the color
         * pair as for the foreground color, though of course that is not
         * necessary:
         */
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_CYAN, COLOR_BLACK);
        init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }

    int row = 1, col = 0;

    mvprintw(0, 0, "COLS = %d, LINES = %d", COLS, LINES);

    for (;;)
    {
        int ch = mvgetch(row, col); /* refresh, accept single keystroke of input */
        mvprintw(0, 0, "COLS = %d, LINES = %d, KEY = %d", COLS, LINES, ch);

        switch (ch)
        {
            case KEY_RESIZE:
            {
                clear();
                mvprintw(0, 0, "COLS = %d, LINES = %d, KEY = %d", COLS, LINES, ch);
                refresh();
                break;
            }

            case 13:
            //case KEY_ENTER:
            {
                row = row + 1;
                col = 0;
                break;
            }

            case KEY_LEFT:
            {
                if (col > 0) 
                    col--;
                break;
            }

            case KEY_RIGHT:
            {
                if (col < COLS) 
                    col++;
                break;
            }

            case KEY_UP:
            {
                if (row > 0) 
                    row--;
                break;
            }

            case KEY_DOWN:
            {
                if (row < LINES) 
                    row++;
                break;
            }

            case KEY_HOME:
            {
                col = 0;
                break;
            }

            case KEY_END:
            {
                break;
            }

            case KEY_BACKSPACE:
            {
                break;
            }

            case KEY_PPAGE:
            {
                break;
            }

            case KEY_NPAGE:
            {
                break;
            }

            default:
            {
                attrset(COLOR_PAIR(num % 8));
                mvaddch(row, col++, ch);
                refresh();
                num++;
                break;
            }
        }
    }

    finish(0); /* we are done */
}

static void finish(int sig)
{
    clear();
    refresh();
    endwin();

    /* do your non-curses wrapup here */

    exit(0);
}
