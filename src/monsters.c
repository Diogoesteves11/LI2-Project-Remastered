#include "../include/monsters.h"

struct monster{
    int MonsterX;
    int MonsterY;
    double hp;
};

//setters

void setMonsterX(Monster *m, int x){
    m->MonsterX = x;
}

void setMonsterY(Monster *m, int y){
    m->MonsterY = y;
}

void setMonsterHp(Monster *m, double hp){
    m->hp = hp;
}

//getters

int getMonsterX(Monster *m){
    return m->MonsterX;
}

int getMonsterY(Monster *m){
    return m->MonsterY;
}

double getMonsterHp(Monster *m){
    return m->hp;
}