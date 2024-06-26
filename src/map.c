#include "../include/map.h"
#include "../include/colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>


struct map_matrix{
    int Max_X;
    int Max_Y;
    char** matrix; //matrix YxX
};
//getters
int get_map_Max_X(Map* m){
    return m->Max_X;
}
int get_map_Max_Y(Map* m){
    return m->Max_Y;
}

char get_map_char(Map* m, int y, int x){
    return m->matrix[y][x];
}

//functions
void insert_on_map(Map* m, char input, int y, int x){
    m->matrix[y][x] = input;
}

void clear_map_pos(Map* m, int y, int x){
    m->matrix[y][x] = ' ';
}

Map* start_map(int max_y, int max_x){
    Map* m = malloc(sizeof(Map));
    m->Max_X = max_x;
    m->Max_Y = max_y;
    m->matrix = (char**)malloc(sizeof(char*) * max_y);
    for(int i = 0; i < max_y; i++){
        m->matrix[i] = (char*) malloc(sizeof(char) * max_x);
    }
    return m;
}

void generate_borders(Map* map, int* count1){
    for (int i = 0; i < map->Max_Y - 1; i++) { // vertical borders
        map->matrix[i][0] = '#';
        map->matrix[i][map->Max_X - 1] = '#';
        mvaddch(i, 0, map->matrix[i][0]);
        mvaddch(i, map->Max_X - 1, map->matrix[i][map->Max_X - 1]);
        (*count1)++;
    }
    for (int i = 0; i < map->Max_X - 1; i++) { // horizontal borders
        map->matrix[0][i] = '#';
        map->matrix[map->Max_Y - 2][i] = '#';
        mvaddch(0, i, map->matrix[0][i]);
        mvaddch(map->Max_Y - 2, i, map->matrix[map->Max_Y - 2][i]);
        (count1)++;
    }
}

void generate_map(Map* map, int max_x, int max_y){
    srand(time(NULL));

    int count1 = 0;

    generate_borders(map,&count1);

    int casas_totais = ((map->Max_X-1) * (map->Max_Y-1)) - count1;
    
    for (int i = 0; i < casas_totais * 0.4; i++) {
        int x1 =  rand() % (map->Max_X - 1);
        int y1 =  rand() % (map->Max_Y - 1);
        map->matrix[y1][x1] = '#';
    }

    for (int i = 0; i < 3; i++) { 
        for (int y = 1; y < (map->Max_Y-2); y++) {
            for (int x = 1; x < (map->Max_X-1) - 1; x++) {
                int count = 0;
                for (int yy = y - 1; yy <= y + 1; yy++) {
                    for (int xx = x - 1; xx <= x + 1; xx++) {
                        if (map->matrix[yy][xx] == '#') {
                            count++;
                        }
                    }
                }
                if (map->matrix[y][x] == '#') {
                    if (count < 3) {
                         map->matrix[y][x] = ' ';
                    }
                } else {
                    if (count > 4) {
                        map->matrix[y][x] = '#';
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < 4; i++) { 
        for (int y = 1; y < (map->Max_Y-1) - 1; y++) {
            for (int x = 1; x < (map->Max_X-1) - 1; x++) {
                int count = 0;
                for (int iy = y - 1; iy <= y + 1; iy++) {
                    for (int ix = x - 1; ix <= x + 1; ix++) {
                        if (map->matrix[iy][ix] == '#' && (iy != y || ix != x)) {
                            count++;
                        }
                    }
                }
                if (map->matrix[y][x] == '#') {
                    if (count < 3) {
                         map->matrix[y][x] = ' ';
                    }
                }
                if (map->matrix[y][x]== ' ') {
                    if (count > 4) {
                        map->matrix[y][x] = '#';
                    }
                }
            }
        }
    }


 for (int i = 1; i < map->Max_Y - 1; i++) {
    for (int j = 1; j < map->Max_X - 1; j++) {
        if (map->matrix[i][j] == '#') {
            int count2 = 0;
            if (map->matrix[i - 1][j] == '#') count2++;
            if (map->matrix[i + 1][j] == '#') count2++;
            if (map->matrix[i][j - 1] == '#') count2++;
            if (map->matrix[i][j + 1] == '#') count2++;

            if (count2 == 0) {
                map->matrix[i][j] = ' '; 
                mvaddch(i, j, map->matrix[i][j]);
            }
        }
    }
}
}

void deleteMap(Map* map) {
    for(int i = 0; i < map->Max_Y; i++){
        free(map->matrix[i]);
    }
    free(map->matrix);
    free(map);
}
