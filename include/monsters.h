#ifndef MONSTERS_H
#define MONSTERS_H

#include "../include/map.h"

typedef struct monster Monster;

void setMonsterX(Monster *m, int x);
void setMonsterY(Monster *m, int y);
void setMonsterHp(Monster *m, double hp);

//setters

int getMonsterX(Monster *m);
int getMonsterY(Monster *m);
double getMonsterHp(Monster *m);

Monster** create_monsters(int num);
void spawn_monsters(Monster** monster, Map* m, int num_enemies);
void free_monsters(Monster** m, int num);

#endif
