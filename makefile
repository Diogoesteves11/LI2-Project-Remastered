CC = gcc #compiler
CFLAGS = -Iinclude -Wall -Wextra -pedantic -O2 -Werror=discarded-qualifiers -g# compilation flags
LDGLAGS = -lm #linking math library

all: game

programa-principal: src/main.o src/state.o src/mapa.h #linking phase_ : $^ targets the dependecies; $@ is equivalent to the target
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@


src/main.o: src/main.c #Empty rules(see full exemple of Guião2.1)
src/mapa.o: src/mapa.c
src/state.o: src/state.c

clean: 
	rm game src/*.o 

