CC = gcc #compiler
CFLAGS = -Iinclude -Wall -Wextra -pedantic -O2 -Werror=discarded-qualifiers -g# compilation flags
LIBS = -lm -lcurses#linking math library

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := .

SRC := $(wildcard $(SRC_DIR)/*.c)

OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TARGET_MAIN := $(BIN_DIR)/game

all: $(TARGET_MAIN)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET_MAIN): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $^ -o $@ $(LIBS)

clean:
	rm -rf $(TARGET_MAIN) $(BUILD_DIR)/*.o log/*.txt src/*.o

rebuild: clean all