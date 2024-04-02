#include "../include/monsters.h"
#include <stdlib.h>
#include <stdio.h>

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

Monster** create_monsters(int num){
   return malloc(sizeof(Monster) * num);
}

void deleteMonsters(Monster** m, int n){
    for(int i = 0; i < n; i++) free(m[i]);
}

