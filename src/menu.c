#include "../include/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>


void show_main_menu(){
    start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    clear();
    
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    
    int menu_width = 20;
    int menu_height = 6;
    int start_x = (cols - menu_width) / 2;
    int start_y = (rows - menu_height) / 2;
    

    attron(COLOR_PAIR(1));
    mvprintw(start_y, start_x, "====================");
    mvprintw(start_y + 1, start_x, "     START MENU");
    mvprintw(start_y + 2, start_x, "====================");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(start_y + 3, start_x, " 1. PLAY GAME");
    mvprintw(start_y + 4, start_x, " 2. GAME DYNAMICS");
    mvprintw(start_y + 5, start_x, " 3. COMMAND LIST");
    mvprintw(start_y + 6, start_x, " 4. SETTINGS");
    mvprintw(start_y + 7, start_x, " 5. EXIT");
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));
    mvprintw(start_y + 8, start_x, "====================");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(start_y + 9, start_x, "  CHOOSE AN OPTION ");
    attroff(COLOR_PAIR(2));

    refresh();
}