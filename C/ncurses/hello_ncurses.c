#include <stdio.h>
#include <ncurses.h>

int main(void)
{

    initscr();

    printw("hello world");
    refresh();
    getch();
    endwin();
}
    
