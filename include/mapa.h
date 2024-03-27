#ifndef MAPA_H
#define MAPA_H

typedef struct map_matrix Map;

Map* start_map(int max_x, int max_y);
void draw_map(Map* m,int map_visibility, int max_x, int max_y);

#endif