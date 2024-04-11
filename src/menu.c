#include "../include/menu.h"
#include "../include/colors.h"
#include "../include/player.h"
#include "../include/mapa.h"
#include "../include/monsters.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>


void show_main_menu(){
    clear();
    
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    
    int menu_width = 20;
    int menu_height = 6;
    int start_x = (cols - menu_width) / 2;
    int start_y = (rows - menu_height) / 2;
    

    attron(COLOR_PAIR(CYAN));
    mvprintw(start_y, start_x, "====================");
    mvprintw(start_y + 1, start_x, "     START MENU");
    mvprintw(start_y + 2, start_x, "====================");
    attroff(COLOR_PAIR(CYAN));

    attron(COLOR_PAIR(WHITE));
    mvprintw(start_y + 3, start_x, " 1. PLAY GAME");
    mvprintw(start_y + 4, start_x, " 2. GAME DYNAMICS");
    mvprintw(start_y + 5, start_x, " 3. COMMAND LIST");
    mvprintw(start_y + 6, start_x, " 4. SETTINGS");
    mvprintw(start_y + 7, start_x, " 5. EXIT");
    attroff(COLOR_PAIR(WHITE));

    attron(COLOR_PAIR(CYAN));
    mvprintw(start_y + 8, start_x, "====================");
    attroff(COLOR_PAIR(CYAN));

    attron(COLOR_PAIR(WHITE));
    mvprintw(start_y + 9, start_x, "  CHOOSE AN OPTION ");
    attroff(COLOR_PAIR(WHITE));

    refresh();
}

void show_settings_menu(int* in_settings, int* num_enemies, int* map_visibility, int* jump_status){
          WINDOW *wnd = initscr();
          int ncols, nrows;
          clear();
          getmaxyx(wnd, nrows, ncols);

            srand48(time(NULL));

            cbreak();
            noecho();
            nonl();
            intrflush(stdscr, false);
            keypad(stdscr, true);

            int startx = ncols /20;
            int starty = nrows/20;

            attron(COLOR_PAIR(WHITE)); 
            mvprintw(starty, (ncols - 7) / 2, "CHOOSE DIFFICULTY");
            if ((*num_enemies) == 5){
             mvprintw(starty + 2, startx, "1.[x] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[ ] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[ ] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[ ] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            else if ((*num_enemies) == 15){
             mvprintw(starty + 2, startx, "1.[ ] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[x] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[ ] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[ ] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            else if ((*num_enemies) == 20){
             mvprintw(starty + 2, startx, "1.[ ] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[ ] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[x] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[ ] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            else if ((*num_enemies) == 30){
             mvprintw(starty + 2, startx, "1.[ ] EASY: 5 enemies");
             mvprintw(starty + 3, startx, "2.[ ] MEDIUM: 15 enemies");
             mvprintw(starty + 4, startx, "3.[ ] HARD: 20 enemies");
             mvprintw(starty + 5, startx, "4.[x] IMPOSSIBLE: 30 enemies");
             clrtoeol();
            }
            if((*jump_status)){
             mvprintw(starty + 7, startx, "5.Activate Jump: ON");
             clrtoeol();
            }else {
              mvprintw(starty + 7, startx, "5.Activate Jump: OFF");
              clrtoeol();
            }
            if((*map_visibility)){
             mvprintw(starty + 8, startx, "6.Map visibility: ON");
             clrtoeol();
            }else {
              mvprintw(starty + 8, startx, "6.Map visibility: OFF");
              clrtoeol();
            }
            mvprintw(nrows-2,1,"PRESS 'q' TO RETURN");
            attroff(COLOR_PAIR(WHITE));

            int key = getch();
            switch(key){
             case 'q': *in_settings = 0;break;
             case '1': *num_enemies = 5;refresh();break;
             case '2': *num_enemies = 15;refresh();break;
             case '3': *num_enemies = 20;refresh();break;
             case '4': *num_enemies = 30;refresh();break;
             case '5': {
              if((*jump_status)){
                *jump_status = 0;refresh();break;
              }else {
                *jump_status = 1;refresh();break;
              }
             }
             case '6': {
              if((*map_visibility)){
                *map_visibility = 0;refresh();break;
              }else {
                *map_visibility = 1;refresh();break;
              }
             }
            }
}

void show_commands_menu(int* in_commands){
          WINDOW *wnd = initscr();
          int ncols, nrows;
          clear();
          getmaxyx(wnd, nrows, ncols);

            srand48(time(NULL));

            cbreak();
            noecho();
            nonl();
            intrflush(stdscr, false);
            keypad(stdscr, true);

            int startx = ncols /20;
            int starty = nrows/20;

            attron(COLOR_PAIR(WHITE)); 
            mvprintw(starty, (ncols - 7) / 2, "CONTROL");

            mvprintw(starty + 2, startx, "t       -> switch gun");
            mvprintw(starty + 3, startx, "w/8     -> move UP");
            mvprintw(starty + 4, startx, "s/2     -> move DOWN");
            mvprintw(starty + 5, startx, "a/4     -> move LEFT");
            mvprintw(starty + 6, startx, "d/6     -> move RIGHT");
            mvprintw(starty + 7, startx, "7       -> move UPPER LEFT");
            mvprintw(starty + 8, startx, "9       -> move UPPER RIGHT");
            mvprintw(starty + 9, startx, "1       -> move DOWN LEFT");
            mvprintw(starty + 10, startx, "3       -> move DOWN RIGHT");
            mvprintw(starty + 11, startx, "SPACE   -> USE WEAPON");
            mvprintw(starty + 12, startx, "5       -> NO MOVEMENT");
            mvprintw(starty + 13, startx, "SHIFT   -> JUMP");


            mvprintw(nrows-2,1,"PRESS 'q' TO RETURN");
            attroff(COLOR_PAIR(WHITE));

            int key = getch();
            switch(key){
             case 'q': *in_commands = 0;refresh();break;
            }
}

void show_game_dynamics_menu(int* in_game_dynamics){
          WINDOW *wnd = initscr();
          int ncols, nrows;
          clear();
          getmaxyx(wnd, nrows, ncols);

            srand48(time(NULL));

            cbreak();
            noecho();
            nonl();
            intrflush(stdscr, false);
            keypad(stdscr, true);

            int starty = nrows/20;

            attron(COLOR_PAIR(WHITE));
            mvprintw(starty,(ncols / 2)-9,"GAME DYNAMICS");
            mvprintw(starty+2,1,"MOVIMENT: ");
            mvprintw(starty+3,2,"1. The player only moves 1 block at a time, in any direction");
            mvprintw(starty+4,2,"2. By pressing the number 5, the player does not move and the game refreshes");
            mvprintw(starty+5,2,"3. The player can only move towards an empty block, or a item such as bullets, traps or heals");
            mvprintw(starty+6,2,"4. The enemies move randomly when they're out of the 10 block radius. Once they're incide the radius, they move towards the player");
            mvprintw(starty+7,2,"5. The player has a 'JUMP' function that can be enabled in settings. This allows the player to move 2 blocks at a time if the next block is valid");

            mvprintw(starty+9,1,"LIGHTING SYSTEM: ");
            mvprintw(starty+10,2,"1.The player has a flashlight that iluminates the map in any direction. The light is dynamic, witch means that it adapts to the map.");

            mvprintw(starty+13,1,"COMBAT: ");
            mvprintw(starty+14,2,"1. Each hit given by the monster to the player reduces the player's hp by 1");
            mvprintw(starty+15,2,"2. Each player starts with 4 hp and 0 bullets.");
            mvprintw(starty+16,2,"3. The hp and bullets are rechargeable, by picking up the loot present on the map");
            mvprintw(starty+17,2,"4. Each hit given by the sword reduces 1hp to the enemy");
            mvprintw(starty+18,2,"5. Each hit given by the gun kills the monster");
            mvprintw(starty+19,2,"6. If the player steps on a trap, the player's hp is divided by 2 until the player is 1hp");
            mvprintw(starty+20,2,"7. The sowrd has a 1 block range while the gun has a unlimited range, enless the bullet hits a wall");
            mvprintw(starty+21,2,"8. The number of enemies is variable, however, when a enemy is killed, another one spawns");
            mvprintw(starty+22,2,"9. The enemies have a 1 block range");
 
           mvprintw(starty+25,1,"NOTES:");
           mvprintw(starty+26,2,"1.The game has a difficulty system that can be change in 'GAME SETTINGS'");
           mvprintw(starty+27,2,"2.Inside the game settings menu, the user can change game dynamics such has the map visibility, the difficulty and the jump");
           mvprintw(nrows-2,1,"PRESS 'q' TO RETURN");
           attroff(COLOR_PAIR(WHITE));

           int key = getch();
           switch(key){
            case 'q': *in_game_dynamics = 0;break;
           }
}

void show_game_submenu(int nrows, int ncols,int num_enemies,int jump_status, int map_visibility, Player* p, Map* m){
    move(nrows - 1, 0);
    attron(COLOR_PAIR(SCORE));
    printw("(%d, %d) %d %d", getPlayerX(p), getPlayerY(p), ncols, nrows);
    clrtoeol();
    printw("    Bullets: %d", getPlayerBullets(p));
    clrtoeol();
    printw("   HP: %d", getPlayerHp(p));
    clrtoeol();
    printw("   KILLS: %d", getPlayerKills(p));
    clrtoeol();
    printw("   EQUIPPED:");
    if (getPlayerSword(p)) {
        printw(" SWORD ");
    } else {
        printw(" GUN");
    }
    clrtoeol();
    printw("   ENEMIES: %d", num_enemies);
    clrtoeol();
    if(jump_status){
        printw("   JUMP: ON");
    }else {
        printw("   JUMP: OFF");
    }
    if(map_visibility){
        printw("   MAP VISIBILITY: ON");
    }else {
        printw("   MAP VISIBILITY: OFF");
    }
    clrtoeol();
    mvprintw(nrows-1,ncols-19,"PRESS 'q' TO RETURN");
    attroff(COLOR_PAIR(SCORE));
}
