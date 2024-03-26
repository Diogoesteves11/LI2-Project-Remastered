#include "../include/mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
struct map_matrix{
    int Max_X;
    int Max_Y;
    char** matrix;
};

Map* start_map(int max_x, int max_y){
    Map* m = malloc(sizeof(Map));
    m->Max_X = max_x;
    m->Max_Y = max_y;
    m->matrix = (char**) malloc(max_x * sizeof(char*));
    for(int i = 0; i < max_y; i++){
        m->matrix[i] = (char*)malloc(max_y * sizeof(char));
    }
    pid_t pid;
    int status;
    for(int r = 0; r < m->Max_X; r++){
        pid = fork();
        if(fork() == 0){
            for(int c = 0; c < m->Max_Y; c++){
                m->matrix [r][c] = '\0'; // starting the map empty
            }
            _exit(0);
        }
    }
    for(int i = 0; i < m->Max_X; i++){
        wait(&status); // adicionar proteção caso o filho nao termine, neste caso confiamos que o fiho termina
    }
    return m;
}


