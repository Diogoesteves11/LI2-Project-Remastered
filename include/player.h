#ifndef PLAYER_H
#define PLAYER_H

typedef struct player Player;

//setters
void setPlayerX(Player *p, int x);
void setPlayerY(Player *p, int y);
void setPlayerHp(Player *p, double hp);
void setPlayerBullets(Player *p, int b);
void setPlayerSword(Player *p, int s);
void setPlayerKills(Player *p, int kills);

//getters

int getPlayerX(Player *p);
int getPlayerY(Player *p);
double getPlayerHp(Player *p);
int getPlayerBullets(Player *p);
int getPlayerSword(Player *p);
int getPlayerKills(Player *p);


#endif