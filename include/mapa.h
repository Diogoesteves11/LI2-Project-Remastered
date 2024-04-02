#ifndef MAPA_H
#define MAPA_H

typedef struct map_matrix Map;

int get_map_Max_X(Map* m);
int get_map_Max_Y(Map* m);
char get_map_char(Map* m, int r, int c);

Map* start_map(int max_x, int max_y);
void generate_map(Map* m,int map_visibility, int max_x, int max_y);
void insert_on_map(Map* m, char input, int r, int l);
void deleteMap(Map* map);

#endif