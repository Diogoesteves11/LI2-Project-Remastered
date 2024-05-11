#include "../include/light.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <math.h>
#include "../include/mapa.h"
#include "../include/player.h"
#include "../include/colors.h"

void draw_light(Map* m, Player* p, int map_visibility){
    int centerX = getPlayerX(p);
    int centerY = getPlayerY(p);

    char wall = '#';
    char trap = 'x';
    char heal = '+';
    char bullet = '-';
    char empty_block = ' ';
    char enemy = '&';
    char damage = '*';
    char explosion = '^';

    double delta = 0.05;

    if(map_visibility){
        init_pair(WALL_COLOR, COLOR_CYAN, COLOR_BLUE);
    }else {
        init_pair(WALL_COLOR, COLOR_BLACK, COLOR_BLACK);
    }
    init_pair(RED,COLOR_RED,COLOR_BLACK);

    for(int y = 0; y < (get_map_Max_Y(m)); y++){
        for(int x = 0; x < (get_map_Max_X(m)); x++){
            if(get_map_char(m,y,x) == wall) {
                attron(COLOR_PAIR(WALL_COLOR));
                mvaddch(y, x, wall);
                attroff(COLOR_PAIR(WALL_COLOR));
            }
        }
    }

    for (double angle = 0; angle < 2 * M_PI; angle += delta){
        double dx = sin(angle);
        double dy = cos(angle);

        double x = centerX + 0.5;
        double y = centerY + 0.5;

        while (x >= 0 && x < (get_map_Max_X(m)) && y >= 0 && y < (get_map_Max_Y(m))){
            char testch = get_map_char(m,(int)y,(int)x);
            if (testch == wall) {
                attron(COLOR_PAIR(WHITE));
                mvaddch(y, x, testch);
                attroff(COLOR_PAIR(WHITE));
                break;
            } else if(testch == enemy){
                attron(COLOR_PAIR(RED));
                mvaddch(y,x,enemy);
                attroff(COLOR_PAIR(RED));
            }
            x+=dx;
            y+=dy;
        }
    }
}