#include "../include/monsters.h"
#include "../include/mapa.h"
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

void spawn_monsters(Map* m, int num_enemies){

}


void deleteMonsters(Monster** monsters, int num_enemies) {
    if (monsters != NULL) {
        for (int i = 0; i < num_enemies; i++) {
            free(monsters[i]);
        }
        free(monsters);
    }
}

