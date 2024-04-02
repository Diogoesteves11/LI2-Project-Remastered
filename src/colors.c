#include "../include/colors.h"
#include <ncurses.h>

void init_colors(){
    start_color();
    init_pair(WHITE,COLOR_WHITE,COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);

    init_pair(PLAYER, COLOR_BLACK, COLOR_GREEN);
    init_pair(MEDIUM_HP, COLOR_BLACK, COLOR_YELLOW);
    init_pair(LOW_HP,COLOR_BLACK,COLOR_RED);

}