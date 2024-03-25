#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "../include/mapa.h"
#include "../include/player.h"
#include "../include/monsters.h"
#include "../include/menu.h"
#include "../include/colors.h"


int main(int argc, char** argv){
    if(argc < 2){
        initscr();
        keypad(stdscr, TRUE);
        curs_set(0);
        noecho();

        start_color();
        init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
        while(1){
            show_main_menu();

            int input = getch();
            clear();

            if(input == '5'){
                endwin();
                printf("GAME CLOSED\n");
                exit(0);
            }
        }

    } else {
        printf("Developer flags current unavalable");
    }

    return 0;
}