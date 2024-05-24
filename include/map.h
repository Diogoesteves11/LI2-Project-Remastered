#ifndef MAP_H
#define MAP_H

typedef struct map_matrix Map;

int get_map_Max_X(Map* m);
int get_map_Max_Y(Map* m);
char get_map_char(Map* m, int y, int x);

Map* start_map(int max_x, int max_y);
void generate_map(Map* m,int max_y, int max_x);
void insert_on_map(Map* m, char input, int r, int l);
void clear_map_pos(Map* m, int y, int x);
void deleteMap(Map* map);

#endif