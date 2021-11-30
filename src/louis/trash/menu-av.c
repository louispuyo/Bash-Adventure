#include <menu.h>
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "../julio/inventaire.h"
#include "../julio/player.h"
#include "Sauvegarde.h"
#include "utils.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 4

void load_item(char *nom);

char *choices[] = {
    "PERSO 1",
    "PERSO 2",
    "PERSO 3",
    "PERSO 4",
    "PERSO 5",
    "LEGENDAIRE",
    "PERSO 7",
    "Exit",
};

int main(int argc, char const *argv[])

{
    ITEM **my_items;

    int c;
    MENU *my_menu;
    int n_choices, i;
    ITEM *cur_item;
    /* Initialize curses */
    char *name_cur_item;
    initscr();
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
    /* Initialize items */
    n_choices = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(choices[i], choices[i]);

    my_items[n_choices] = (ITEM *)NULL;
    //  item_opts_off(my_items[3], O_SELECTABLE);
    item_opts_off(my_items[6], O_SELECTABLE); // si pas encore debloquer
    /* Create menu */
    my_menu = new_menu((ITEM **)my_items);
    /* Set fore ground and back ground of the menu */
    set_menu_fore(my_menu, COLOR_PAIR(1) | A_REVERSE);
    set_menu_back(my_menu, COLOR_PAIR(2));
    set_menu_grey(my_menu, COLOR_PAIR(3));
    /* Post the menu */
    mvprintw(LINES - 3, 0, "Press <ENTER> to see the option selected");
    mvprintw(LINES - 2, 0, "Up and Down arrow keys to naviage (F8 to Exit)");
    post_menu(my_menu);
    refresh();
    while ((c = getch()) != KEY_F(8) && (c =getch()) != 10)
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;

        case ' ':
            menu_driver(my_menu, REQ_TOGGLE_ITEM);
            break;

        case 10: /* Enter */
        {

          endwin();
          
        system("./choose_perso");
        exit(0);
        break;
        
            
        }
                    // refresh();

        break;
        }
        
    }
    unpost_menu(my_menu);
    for (i = 0; i < n_choices; ++i)
        free_item(my_items[i]);
    free_menu(my_menu);
    endwin();
    refresh();
    

}
