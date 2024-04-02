#include "../include/engine.h"
#include "../include/mapa.h"
#include "../include/colors.h"
#include "../include/monsters.h"
#include "../include/player.h"
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


void run_game(int* in_game, int num_enemies, int map_visibility){
    WINDOW *wnd = initscr();
    int ncols, nrows;
    clear();
    getmaxyx(wnd, ncols, nrows);

    srand48(time(NULL));
    start_color();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, false);
    keypad(stdscr, true);
    init_pair(WHITE,COLOR_WHITE,COLOR_BLACK);

    Monster** monster_array = create_monsters(num_enemies); //  FREE ATE THE END
    Player* player = start_player(); //FREE AT THE END

    clear();
    Map* map = start_map(nrows,ncols);
    generate_map(map, map_visibility, nrows , ncols);
    spawn_player(player,map);
    while((*in_game)){
        draw_player(player,map);
        if((*in_game) == 0) break;
        char input = getch();
        if(input == 'q') (*in_game) = 0;
    }
    deletePlayer(player);
    deleteMonsters(monster_array, num_enemies);
}
