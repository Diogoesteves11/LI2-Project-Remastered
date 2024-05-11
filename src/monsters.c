#include "../include/monsters.h"
#include "../include/mapa.h"
#include <stdlib.h>
#include <stdio.h>

struct monster{
    int id;
    int MonsterX;
    int MonsterY;
    double hp;
};

//setters

void setMonsterID(Monster* m, int id){
    m->id = id;
}

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

int getMonsterID(Monster* m){
    return m->id;
}

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
   Monster** m =  malloc(sizeof(Monster) * num);
   for(int i = 1; i <= num; i++){
       m[i]->id = i;
   }
   return m;
}

void spawn_monsters(Monster** monster, Map* m, int num_enemies){
    int ix,iy;
    for (int i = 0; i < num_enemies; i++){
        do{
            ix = 1 + (rand() % get_map_Max_X(m)- 2);
            iy = 1 + (rand() % get_map_Max_Y(m) - 2);
        }while(get_map_char(m,iy,ix) != ' ');
        insert_on_map(m,'&',iy,ix);

        monster[i]->MonsterY = iy;
        monster[i]->MonsterX = ix;
        monster[i]->hp = 2.0;
    }
}


void deleteMonsters(Monster** monsters, int num_enemies) {
    if (monsters != NULL) {
        for (int i = 0; i < num_enemies; i++) {
            free(monsters[i]);
        }
        free(monsters);
    }
}

