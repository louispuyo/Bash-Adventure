#include <curses.h>
#include <stdlib.h>
#include "../julio/player.h"

#define HERBES  	  ' '
#define EMPTY     ' '
#define EAU	  'h'
#define MONTAGNE  '^'
#define PLAYER	  '*'
#define BOMBE     'b'
#define TRAI '_'


int is_move_okay(int y, int x);
void draw_map(void);


int main(void)
{
    int y, x;
    int ch;


    // INIT PLAYER 
    

    
    /* initialize curses */

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();

    clear();

    /* initialize the quest map */
   
    draw_map();
    

    /* start player at lower-left */

    y = LINES - 15;
    x = 40;

    do {
	/* by default, you get a blinking cursor - use it to indicate player */

	mvaddch(y, x, PLAYER);
	move(y, x);
	refresh();

	ch = getch();

	/* test inputted key and determine direction */

	switch (ch) {
	case KEY_UP:
	case 'w':
	case 'W':
	    if ((y > 0) && is_move_okay(y - 1, x)) {
		mvaddch(y, x, EMPTY);
		y = y - 1;
	    }
	    break;
	case KEY_DOWN:
	case 's':
	case 'S':
	    if ((y < LINES - 1) && is_move_okay(y + 1, x)) {
		mvaddch(y, x, EMPTY);
		y = y + 1;
	    }
	    break;
	case KEY_LEFT:
	case 'a':
	case 'A':
	    if ((x > 0) && is_move_okay(y, x - 1)) {
		mvaddch(y, x, EMPTY);
		x = x - 1;
	    }
	    break;

    case KEY_ENTER:
    case 'm':
    case 'M':
    if ((x > 0) && is_move_okay(y, x - 1)){

        mvaddch(y,x, BOMBE);
        
        printw("<+>");
        
        break;
    }
        

	case KEY_RIGHT:
	case 'd':
	case 'D':
	    if ((x < COLS - 1) && is_move_okay(y, x + 1)) {
		mvaddch(y, x, EMPTY);
		x = x + 1;
	    }
	    break;

	}
    }
    while ((ch != 'q') && (ch != 'Q'));

    endwin();

    exit(0);
}

int is_move_okay(int y, int x)
{
    int testch;

    /* return true if the space is okay to move into */

    testch = mvinch(y, x);
    return ((testch == HERBES) || (testch == EMPTY));
}

void draw_map(void)
{
    int y, x;
    Entity *player_1;
    initEnt(&player_1);
    initWarrior(&player_1);
    /* draw the quest map */

    /* background */

    for (y = 5; y < LINES; y++) {
	mvhline(y, 5, HERBES, COLS);
    }


    for (x = COLS/3; x<(COLS/4)+1; x++)
    {
        mvhline(0, x, TRAI, COLS);
    }

    /* MONTAGNE */

    for (x = COLS / 3; x < (COLS/3)+1; x++) {
	mvvline(0, x, TRAI, LINES);
    }

    // DISP
    affIt(player_1, 1, 10);
    afficheInvent(player_1->inventaire);


    // mvhline(LINES / 4, 0, HERBES, COLS);

    /* lake */

    for (y = 1; y < LINES / 2; y++) {
	// mvhline(y, 1, EAU, COLS / 3);
    }
}


