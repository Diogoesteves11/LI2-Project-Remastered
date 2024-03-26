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
        int map_visibility = 0;
        int jump_status = 0;
        int in_settings = 0;
        int num_enemies = 5;
        while(1){
            show_main_menu();

            int input = getch();
            clear();
            switch (input){
                case '4':
                        in_settings = 1;
                        while(in_settings){
                            show_settings_menu(&in_settings,&num_enemies,&map_visibility,&jump_status);
                        }
                        break;
                case '5':
                        endwin();
                        printf("GAME CLOSED\n");
                        exit(0);
                        break;
            }
        }

    } else {
        printf("Developer flags current unavalable");
    }

    return 0;
}