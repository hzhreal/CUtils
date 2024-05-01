# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude

# Source directory
SRC_DIR = source

# Include directory
INC_DIR = include

# Object directory
OBJ_DIR = obj

# Library directory
LIB_DIR = lib

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Library name
LIB_NAME = libcutils.a

# Target
TARGET = $(LIB_DIR)/$(LIB_NAME)

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build library
$(TARGET): $(OBJS)
	@mkdir -p $(@D)
	ar rcs $@ $^

.PHONY: all clean

# Build all
all: $(TARGET)

# Clean objects and library
clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)