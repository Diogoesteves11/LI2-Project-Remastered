#ifndef MONSTERS_H
#define MONSTERS_H

typedef struct monster Monster;

void setMonsterX(Monster *m, int x);
void setMonsterY(Monster *m, int y);
void setMonsterHp(Monster *m, double hp);

//setters

int getMonsterX(Monster *m);
int getMonsterY(Monster *m);
double getMonsterHp(Monster *m);

#endif