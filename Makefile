# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Target executable name
TARGET = maze

# Find all .c files in the directory
ALL_SRCS = $(wildcard *.c)

# Separate main.c and other sources
MAIN_SRC = main.c
OTHER_SRCS = $(filter-out main.c, $(ALL_SRCS))

# Object file for main.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)

# Default target to build the program
.PHONY: all
all: CFLAGS += -O2 # For optimization
all: $(TARGET)

# Debug build (-g flag)
.PHONY: debug
debug: CFLAGS += -g
debug: $(TARGET)

# Link main.o with other source files directly
$(TARGET): $(MAIN_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN_OBJ) $(OTHER_SRCS)

# Rule to compile main.c into main.o
$(MAIN_OBJ): $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Clean up object files and the executable
.PHONY: clean
clean:
	rm -f $(MAIN_OBJ) $(TARGET)
	rm -rf $(TARGET).dSYM
