#ifndef PLAYER_H
#define PLAYER_H

typedef struct player Player;

#define N 19 
#define S 20
#define E 21
#define W 22
#define NW 23
#define SW 24
#define NE 25
#define SE 26
#define NO_DIRECTION 27


//setters
void setPlayerX(Player *p, int x);
void setPlayerY(Player *p, int y);
void setPlayerHp(Player *p, double hp);
void setPlayerBullets(Player *p, int b);
void setPlayerSword(Player *p, int s);
void setPlayerKills(Player *p, int kills);
void setPlayerDirection(Player* p, int direction);

//getters

int getPlayerX(Player *p);
int getPlayerY(Player *p);
double getPlayerHp(Player *p);
int getPlayerBullets(Player *p);
int getPlayerSword(Player *p);
int getPlayerKills(Player *p);
int getPlayerDirection(Player* p);

Player* start_player();

#endif