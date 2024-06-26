#include "../include/engine.h"
#include "../include/map.h"
#include "../include/colors.h"
#include "../include/monsters.h"
#include "../include/player.h"
#include "../include/menu.h"
#include "../include/light.h"
#include "../include/update.h"
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void run_game(int* in_game, int num_enemies, int map_visibility, int jump_status, int y, int x){
    clear();

    //Monster** monster_array = create_monsters(num_enemies);
    Player* player = start_player();
    Map* map = start_map(y,x);

    generate_map(map, y , x);
    spawn_player(player,map);
    //spawn_monsters(monster_array,map,num_enemies);

    while((*in_game)){
        clear();
        show_game_submenu(y, x, num_enemies, jump_status, map_visibility, player, map);

        draw_player(player,map);
        draw_light(map,player, map_visibility);

        if((*in_game) == 0) break;

        char input = getch();
        if(input == 'q') (*in_game) = 0;

        update_player(player,map,input);
    }
    deletePlayer(player);
    //free_monsters(monster_array,num_enemies);
    deleteMap(map);
}
