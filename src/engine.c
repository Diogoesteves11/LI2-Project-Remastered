#include "../include/engine.h"
#include "../include/mapa.h"
#include "../include/colors.h"
#include "../include/monsters.h"
#include "../include/player.h"
#include "../include/menu.h"
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void run_game(int* in_game, int num_enemies, int map_visibility, int jump_status, int nrows, int ncols){
    clear();

    Monster** monster_array = create_monsters(num_enemies);
    Player* player = start_player();

    Map* map = start_map(nrows,ncols);
    generate_map(map, map_visibility, nrows , ncols);
    spawn_player(player,map);
    while((*in_game)){
        draw_player(player,map);
        show_game_submenu(get_map_Max_X(map), get_map_Max_Y(map), num_enemies, jump_status, map_visibility, player, map);
        if((*in_game) == 0) break;
        char input = getch();
        if(input == 'q') (*in_game) = 0;
    }
    deletePlayer(player);
    deleteMonsters(monster_array, num_enemies);
    deleteMap(map);
}
