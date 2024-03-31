#include "../include/mapa.h"
#include "../include/colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
struct map_matrix{
    int Max_X;
    int Max_Y;
    char** matrix;
};

Map* start_map(int max_x, int max_y){
    Map* m = malloc(sizeof(Map));
    m->Max_X = max_x;
    m->Max_Y = max_y;
    return m;
}

void draw_map(Map* map,int map_visibility, int max_x, int max_y){
    srand(time(NULL));
    start_color();
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    int wall_color = 0;
    if(map_visibility){
     init_pair(wall_color, COLOR_CYAN, COLOR_BLUE);
    }else {
        init_pair(wall_color, COLOR_BLACK, COLOR_BLACK);
    }


    int count1 = 0;
    
    attron(COLOR_PAIR(wall_color));
    for (int i = 0; i < map->Max_X; i++) {
        map->matrix[i][0] = '#'; 
        map->matrix[i][map->Max_Y - 2] = '#';
        mvaddch(0, i, map->matrix[i][0]);
        mvaddch(map->Max_Y - 2, i, map->matrix[i][map->Max_Y - 2]);
        count1++;
    }
    for (int i = 0; i < map->Max_Y - 1; i++) {
        map->matrix[0][i] = '#'; 
        map->matrix[map->Max_X - 1][i] = '#'; 
        mvaddch(i, 0, map->matrix[0][i]);
        mvaddch(i, map->Max_X - 1, map->matrix[map->Max_X - 1][i]);
        count1++;
    }
   
    for (int i = 1; i < map->Max_X - 1; i++) {
        map->matrix[i][map->Max_Y - 1] = ' '; 
        mvaddch(map->Max_Y - 1, i, map->matrix[i][map->Max_Y - 1]);
    }
    int casas_totais = ((map->Max_X) * (map->Max_Y)) - count1;
    int heal_percentage = casas_totais * 0.01;
    int heal_count = 0;
    int trap_count = 0;
    int trap_percentage = casas_totais * 0.01;
    int bullet_count = 0;
    int bullet_percentage = casas_totais * 0.01;

    
    for (int i = 0; i < casas_totais * 0.4; i++) {
        int x1 = 2 + rand() % (map->Max_X - 2); 
        int y1 = 2 + rand() % (map->Max_Y - 2);
        map->matrix[x1][y1] = '#';
        mvaddch(y1, x1, map->matrix[x1][y1]);
    }

    for (int i = 0; i < 3; i++) { 
        for (int y = 1; y < (map->Max_Y-1) - 1; y++) {
            for (int x = 1; x < (map->Max_X) - 1; x++) {
                int count = 0;
                for (int yy = y - 1; yy <= y + 1; yy++) {
                    for (int xx = x - 1; xx <= x + 1; xx++) {
                        if (map->matrix[xx][yy] == '#') {
                            count++;
                        }
                    }
                }
                if (map->matrix[x][y] == '#') {
                    if (count < 3) {
                         attroff(COLOR_PAIR(wall_color));
                         attron (COLOR_PAIR(BLACK));
                        map->matrix[x][y] = ' ';
                        mvaddch(y,x,map->matrix[x][y]);
                         attroff(COLOR_PAIR(BLACK));
                         attron (COLOR_PAIR(BLACK));
                    }
                } else {
                    if (count > 4) {
                        map->matrix[x][y] = '#';
                        mvaddch(y,x,map->matrix[x][y]);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 4; i++) { 
        for (int y = 1; y < (map->Max_Y-1) - 1; y++) {
            for (int x = 1; x < (map->Max_X) - 1; x++) {
                int count = 0;
                for (int iy = y - 1; iy <= y + 1; iy++) {
                    for (int ix = x - 1; ix <= x + 1; ix++) {
                        if (map->matrix[ix][iy] == '#' && (iy != y || ix != x)) {
                            count++;
                        }
                    }
                }
                if (map->matrix[x][y] == '#') {
                    if (count < 3) {
                         attroff(COLOR_PAIR(wall_color));
                         attron (COLOR_PAIR(BLACK));
                        map->matrix[x][y] = ' ';
                        mvaddch(y,x,map->matrix[x][y]);
                         attroff(COLOR_PAIR(BLACK));
                         attron (COLOR_PAIR(BLACK));
                    }
                }
                if (map->matrix[x][y]== ' ') {
                    if (count > 4) {
                        map->matrix[x][y] = '#';
                        mvaddch(y,x,map->matrix[x][y]);
                    }
                }
            }
        }
    }


 for (int i = 1; i < map->Max_X - 1; i++) {
    for (int j = 1; j < map->Max_Y - 1; j++) {
        if (map->matrix[i][j] == '#') {
            int count2 = 0;
            if (map->matrix[i - 1][j] == '#') count2++; 
            if (map->matrix[i + 1][j] == '#') count2++; 
            if (map->matrix[i][j - 1] == '#') count2++; 
            if (map->matrix[i][j + 1] == '#') count2++; 

            if (count2 == 0) {
                attroff(COLOR_PAIR(wall_color));
                attron (COLOR_PAIR(BLACK));
                map->matrix[i][j] = ' '; 
                mvaddch(j, i, map->matrix[i][j]);
                attroff(COLOR_PAIR(BLACK));
                attron(COLOR_PAIR(wall_color));
            }
        }
    }
}
attroff(COLOR_PAIR(wall_color));
//#endregion

// #region MAP_ITEMS 
attron (COLOR_PAIR(BLACK));
while  (trap_count < trap_percentage) {
 int x1 = rand() % (map->Max_X - 2) + 1;
 int y1 = rand() % (map->Max_Y - 1);
 if (map->matrix [x1] [y1] != '#') {
  map->matrix[x1][y1] = 'x';
  mvaddch(y1, x1, map->matrix[x1][y1]);
 }
 trap_count ++;
 }
attroff(COLOR_PAIR(BLACK));

attron (COLOR_PAIR(BLACK));
while  (heal_count < heal_percentage) {
 int x1 = rand() % (map->Max_X - 2) + 1;
 int y1 = rand() % (map->Max_Y - 1);
 if (map->matrix [x1] [y1] != '#') {
  map->matrix[x1][y1] = '+';
  mvaddch(y1, x1, map->matrix[x1][y1]);
 }
 heal_count ++;
 }
attroff(COLOR_PAIR(BLACK));

attron (COLOR_PAIR(BLACK));
while  (bullet_count < bullet_percentage) {
 int x1 = rand() % (map->Max_X - 2) + 1;
 int y1 = rand() % (map->Max_Y - 1);
 if (map->matrix [x1] [y1] != '#') {
  map->matrix[x1][y1] = '-';
  mvaddch(y1, x1, map->matrix[x1][y1]);
 }
 bullet_count ++;
 }
attroff(COLOR_PAIR(BLACK));
}
