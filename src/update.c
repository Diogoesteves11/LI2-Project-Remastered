#include "../include/update.h"
#include "../include/monsters.h"
#include "../include/player.h"
#include "../include/map.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void update_player(Player* p,Map* m,char input){
    switch(input){
        case 'w':
            move_player(p,m,-1,0);break;
        case 's':
            move_player(p,m,1,0);break;
        case 'a':
            move_player(p,m,0,-1);break;
        case 'd':
            move_player(p,m,0,1);break;
    }
}
