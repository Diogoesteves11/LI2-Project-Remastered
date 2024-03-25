CC = gcc #compiler
CFLAGS = -Iinclude -Wall -Wextra -pedantic -O2 -Werror=discarded-qualifiers -g# compilation flags
LIBS = -lm -lcurses#linking math library

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := .

# Lista de todos os arquivos de origem
SRC := $(wildcard $(SRC_DIR)/*.c)

# Lista de arquivos-objeto
OBJ := $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Nomes dos executáveis finais
TARGET_MAIN := $(BIN_DIR)/game

# Regras padrão - compilar todos os arquivos-objeto e linkar os executáveis
all: $(TARGET_MAIN)

# Regra para compilar os arquivos-objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ 

# Regra para linkar o executável do programa principal
$(TARGET_MAIN): $(OBJ)
	@mkdir -p $(@D)
	$(CC) $^ -o $@ $< $(LIBS)

# Limpar arquivos intermediários
clean:
	rm -rf game $(BUILD_DIR) log/*.txt
	
# Fazer clean e depois compilar novamente
rebuild: clean-all all

# Indicar que "clean", "clean-all", "rebuild" não são arquivos
.PHONY: clean clean-all rebuild