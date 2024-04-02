#ifndef MENU_H
#define MENU_H

#include "../include/player.h"
#include "../include/monsters.h"

void show_main_menu();
void show_settings_menu(int* in_settings, int* num_enemies, int* map_visibility, int* jump_status);
void show_commands_menu(int* in_commands);
void show_game_dynamics_menu(int* in_game_dynamics);
void show_game_submenu(int y, int x,int num_enemies,int jump_status , int map_visibility, Player* p, Map* m);

#endif