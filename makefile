# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR) -fPIC 

# Directories
BIN_DIR = bin
INCLUDE_DIR = include
LIB_DIR = lib
SRC_DIR = src
LIB_NAME = $(LIB_DIR)/libcustomutils.a

# Defines object files with paths to bin/
OBJ_FILES = $(BIN_DIR)/fetch_utils.o $(BIN_DIR)/print_utils.o $(BIN_DIR)/sort_utils.o

# Targets for the static library
$(LIB_NAME): $(OBJ_FILES) | $(LIB_DIR)  # Ensure LIB_DIR is created
	ar rcs $(LIB_NAME) $(OBJ_FILES)  # Create static library

# Ensures the bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Ensures the lib directory exists
$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Compiles each .c file from src/ into an object file inside bin/
$(BIN_DIR)/fetch_utils.o: $(SRC_DIR)/fetch_utils.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/fetch_utils.c -o $(BIN_DIR)/fetch_utils.o

$(BIN_DIR)/print_utils.o: $(SRC_DIR)/print_utils.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/print_utils.c -o $(BIN_DIR)/print_utils.o

$(BIN_DIR)/sort_utils.o: $(SRC_DIR)/sort_utils.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/sort_utils.c -o $(BIN_DIR)/sort_utils.o

# Installs command to copy library and header files to ucrt64
install: $(LIB_NAME)
	@echo "Copying static library and header files to MSYS2 ucrt64 paths"
	@cp -f $(LIB_NAME) /ucrt64/lib/
	@cp -f $(INCLUDE_DIR)/custom_utils.h /ucrt64/include/

# Target to build a main program that uses the library
main: main.c $(LIB_NAME)
	$(CC) $(CFLAGS) main.c -L$(LIB_DIR) -lcustomutils -o main

# Cleans up object files, the library, and the main program
clean:
	rm -rf $(BIN_DIR)/*.o $(LIB_NAME) main

.PHONY: all install clean
