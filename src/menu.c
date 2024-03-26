#include "../include/menu.h"
#include "../include/colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>


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

void show_settings_menu(int* in_settings, int* num_enemies, int* map_visibility, int* jump_status){
          WINDOW *wnd = initscr();
          int ncols, nrows;
          clear();
          getmaxyx(wnd, nrows, ncols);

            srand48(time(NULL));
            start_color();

            cbreak();
            noecho();
            nonl();
            intrflush(stdscr, false);
            keypad(stdscr, true);

            init_pair(WHITE,COLOR_WHITE,COLOR_BLACK);
            init_pair(1, COLOR_CYAN, COLOR_BLACK);
	        init_pair(2, COLOR_YELLOW, COLOR_BLACK);

            int startx = ncols /20;
            int starty = nrows/20;

            attron(COLOR_PAIR(WHITE)); 
            mvprintw(starty, (ncols - 7) / 2, "CHOOSE DIFFICULTY");
            if ((*num_enemies) == 5){
             mvprintw(starty + 2, startx, "1.[x] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[ ] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[ ] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[ ] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            else if ((*num_enemies) == 15){
             mvprintw(starty + 2, startx, "1.[ ] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[x] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[ ] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[ ] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            else if ((*num_enemies) == 20){
             mvprintw(starty + 2, startx, "1.[ ] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[ ] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[x] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[ ] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            else if ((*num_enemies) == 30){
             mvprintw(starty + 2, startx, "1.[ ] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[ ] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[ ] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[x] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            if((*jump_status)){
             mvprintw(starty + 7, startx, "5.Activate Jump: ON");
             clrtoeol();
            }else {
              mvprintw(starty + 7, startx, "5.Activate Jump: OFF");
              clrtoeol();
            }
            if((*map_visibility)){
             mvprintw(starty + 8, startx, "6.Map visibility: ON");
             clrtoeol();
            }else {
              mvprintw(starty + 8, startx, "6.Map visibility: OFF");
              clrtoeol();
            }
            mvprintw(nrows-2,1,"PRESS 'q' TO RETURN");
            attroff(COLOR_PAIR(WHITE));

            int key = getch();
            switch(key){
             case 'q': *in_settings = 0;break;
             case '1': *num_enemies = 5;refresh();break;
             case '2': *num_enemies = 15;refresh();break;
             case '3': *num_enemies = 20;refresh();break;
             case '4': *num_enemies = 30;refresh();break;
             case '5': {
              if((*jump_status)){
                *jump_status = 0;refresh();break;
              }else {
                *jump_status = 1;refresh();break;
              }
             }
             case '6': {
              if((*map_visibility)){
                *map_visibility = 0;refresh();break;
              }else {
                *map_visibility = 1;refresh();break;
              }
             }
            }
}
