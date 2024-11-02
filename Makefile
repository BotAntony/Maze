# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target executable name
TARGET = maze

# Automatically find all .c files in the current directory
SRCS = $(wildcard *.c)

# Print the source files detected (for debugging)
$(info Source files: $(SRCS))

# Automatically convert each .c file to a .o file
OBJS = $(SRCS:.c=.o)

# Default target to build the program
all: $(TARGET)

# Rule to link object files into the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile each .c file into an .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean

