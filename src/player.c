#include "../include/player.h"

struct player{
    int playerX;
	int playerY;
	double hp;
	int bullets;
	int sword;
	int kills;
};

//setters
void setPlayerX(Player *p, int x){
    p->playerX = x;
}

void setPlayerY(Player *p, int y){
    p->playerY = y;
}

void setPlayerHp(Player *p, double hp){
    p->hp = hp;
}

void setPlayerBullets(Player *p, int b){
    p->bullets = b;
}

void setPlayerSword(Player *p, int s){
    p->sword = s;
}

void setPlayerKills(Player *p, int kills){
    p->kills = kills;
}

//getters

int getPlayerX(Player *p){
    return p->playerX;
}

int getPlayerY(Player *p){
    return p->playerY;
}

double getPlayerHp(Player *p){
    return p->hp;
}
int getPlayerBullets(Player *p){
    return p->bullets;
}

int getPlayerSword(Player *p){
    return p->sword;
}

int getPlayerKills(Player *p){
    return p->kills;
}
