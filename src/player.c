#include "../include/player.h"

struct player{
    int playerX;
	int playerY;
	double hp;
	int bullets;
	int sword;
	int kills;
    int last_direction;
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

void setPlayerDirection(Player* p, int direction){
    p->last_direction = direction;
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

int getPlayerDirection(Player* p){
    return p->last_direction;
}

Player* start_player(){
    Player* new_player = malloc(sizeof(Player));
    setPlayerX(new_player,20);
    setPlayerY(new_player, 20);
    setPlayerHp(new_player,3);
    setPlayerKills(new_player,0);
    setPlayerSword(new_player,1);
    setPlayerBullets(new_player,5);
    setPlayerDirection(new_player, NO_DIRECTION);
    return new_player;
}
