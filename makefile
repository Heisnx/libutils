# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I.    # Include current directory for headers

# Directories
BIN_DIR = bin
SRC_DIR = src
LIB_NAME = libutils.a

# Define object files with paths to bin/
OBJ_FILES = $(BIN_DIR)/fetch_utils.o $(BIN_DIR)/print_utils.o $(BIN_DIR)/sort_utils.o

# Target for the static library
$(LIB_NAME): $(OBJ_FILES)
	ar rcs $(LIB_NAME) $(OBJ_FILES)

# Ensure the bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Compile each .c file from src/ into an object file inside bin/
$(BIN_DIR)/fetch_utils.o: $(SRC_DIR)/fetch_utils.c main_utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/fetch_utils.c -o $(BIN_DIR)/fetch_utils.o

$(BIN_DIR)/print_utils.o: $(SRC_DIR)/print_utils.c main_utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/print_utils.c -o $(BIN_DIR)/print_utils.o

$(BIN_DIR)/sort_utils.o: $(SRC_DIR)/sort_utils.c main_utils.h | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/sort_utils.c -o $(BIN_DIR)/sort_utils.o

# Target to build a main program that uses the library
main: main.c $(LIB_NAME)
	$(CC) $(CFLAGS) main.c -L. -lutils -o main

# Clean up object files, the library, and the main program
clean:
	rm -rf $(BIN_DIR) $(LIB_NAME) main
