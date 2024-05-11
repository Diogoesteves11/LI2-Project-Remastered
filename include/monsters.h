#ifndef MONSTERS_H
#define MONSTERS_H

#include "../include/mapa.h"

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
void deleteMonsters(Monster** m, int num_enemies);

#endif