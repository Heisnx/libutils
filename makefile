# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude  # Added include directory for header files

# Directories
BIN_DIR = bin
INCLUDE_DIR = include
LIB_DIR = lib
SRC_DIR = src
LIB_NAME = $(LIB_DIR)/libutils.a

# Define object files with paths to bin/
OBJ_FILES = $(BIN_DIR)/fetch_utils.o $(BIN_DIR)/print_utils.o $(BIN_DIR)/sort_utils.o

# Target for the static library
$(LIB_NAME): $(OBJ_FILES) | $(LIB_DIR)  # Ensure LIB_DIR is created
	ar rcs $(LIB_NAME) $(OBJ_FILES)

# Ensure the bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Ensure the lib directory exists
$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Compile each .c file from src/ into an object file inside bin/
$(BIN_DIR)/fetch_utils.o: $(SRC_DIR)/fetch_utils.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/fetch_utils.c -o $(BIN_DIR)/fetch_utils.o

$(BIN_DIR)/print_utils.o: $(SRC_DIR)/print_utils.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/print_utils.c -o $(BIN_DIR)/print_utils.o

$(BIN_DIR)/sort_utils.o: $(SRC_DIR)/sort_utils.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/sort_utils.c -o $(BIN_DIR)/sort_utils.o

# Install command to copy library and header files
install: $(LIB_NAME)
	install -Dm644 $(LIB_NAME) /usr/local/lib/$(LIB_NAME)  # Update this if necessary
	install -Dm644 $(INCLUDE_DIR)/utils.h /usr/local/include/utils.h

# Target to build a main program that uses the library
main: main.c $(LIB_NAME)
	$(CC) $(CFLAGS) main.c -L$(LIB_DIR) -lutils -o main  # Use -L$(LIB_DIR) to link

# Clean up object files, the library, and the main program
clean:
	rm -rf $(BIN_DIR) $(LIB_NAME) main
