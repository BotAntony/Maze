# Compiler and base flags
CC = gcc
CFLAGS = -Wall
# Directory for source files
SRC_DIR = src
# Directory for binaries
BIN_DIR = bin

# Find all .c files in the source directory
SRCS = $(wildcard $(SRC_DIR)/*.c)
GAME_SRCS = $(filter-out $(SRC_DIR)/print_maze.c, $(SRCS))

# Define executables
GAME_EXEC = $(BIN_DIR)/maze
PRINT_EXEC = $(BIN_DIR)/print_maze

# Source files for each executable
PRINT_SRCS = $(SRC_DIR)/print_maze.c $(SRC_DIR)/maze_gen.c $(SRC_DIR)/stack.c

# Default target to build everything
.PHONY: all
all: $(BIN_DIR) $(GAME_EXEC) $(PRINT_EXEC)

# Rule to build the game executable
$(GAME_EXEC): $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(GAME_EXEC) $(GAME_SRCS) -lncurses

# Rule to build the print_maze executable
$(PRINT_EXEC): $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(PRINT_EXEC) $(PRINT_SRCS)

# ensure `bin` folder exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Debug target for both executables
.PHONY: debug
debug: CFLAGS += -g
debug: all

# Clean up executables and .dSYM directory
.PHONY: clean
clean:
	rm -f $(GAME_EXEC) $(PRINT_EXEC)
	rm -rf $(GAME_EXEC).dSYM $(PRINT_EXEC).dSYM
	rm -rf $(BIN_DIR)

