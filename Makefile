# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -lSDL2
LFLAGS = -lSDL2
# Directories
SRC_DIR = src
OBJ_DIR = .obj

# Source and object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Executable
TARGET = game

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g -fsanitize=address
debug: clean all

# Clean rule
clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
