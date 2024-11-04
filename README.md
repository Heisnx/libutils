# Utility Functions for C

[![Version](https://img.shields.io/badge/version-v1.1.0-red.svg)](https://shields.io/)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://choosealicense.com/)

A collection of utility functions for C programming, designed to simplify common tasks such as printing, sorting, and fetching user input. This small project is still a work in progress.

## Table of Contents

- [Features](#features)
- [Function Types](#function-types)
- [Installation](#installation)
- [Usage](#usage)
- [Symbol Notation](#symbol-notation)
- [Notes](#notes)
- [Compatibility](#compatibility)

## Features

- **Printing Functions**: Easily print arrays and separators.
- **Sorting Algorithms**: Implementations of insertion sort and quick sort.
- **Input Handling**: Fetch a variety of values with error-checking.
- **Array Handling**: Fill a variety of array types with error-checking.

## Function Types

- **Fetching functions**: Used to get information from the user.
- **Printing functions**: Used to print information.
- **Sorting functions**: Used to sort arrays and datasets.

## Installation

To integrate the `libutils` library into your system, follow these steps:

1. Clone this repository to your machine
2. Create a `build` directory within the root directory of this repository:

```bash
mkdir build
cd build
```

3. Make sure that you have CMake installed on your machine.
4. Within the build directory, run this code:

```bash
cmake ..
cmake --build .
cmake --install . --prefix "<your-active-compiler-path>"
```

5. If you wish to install this library to the default location (e.g., C:\Program Files (x86)), you can run the install command without specifying the prefix:

```bash
cmake --install .
```

## Usage

This part will include the simplest definitions of a `Makefile` and `CMakeLists.txt` files
to demonstrate the usage of the library.

**WARNING:** Always replace `"<your-active-compiler-path/lib>"` and `"<your-active-compiler-path/include>"` with the actual paths where the library and header files are installed.

### Makefile

```makefile
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I. -Wall -g  # Include current directory for header file

# Source files
SRCS = main.c

# Executable name
EXEC = program.exe

# Default target
all: $(EXEC)

# Link the object files to create the executable
$(EXEC): $(SRCS)
	$(CC) $(SRCS) -o $(EXEC) -L"<your-active-compiler-path/lib>" -lcustomutils

# Clean up
clean:
	rm -f $(EXEC)

.PHONY: all clean
```

### CMake

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Find the customutils library
find_library(CUSTOMUTILS_LIB customutils PATHS "<your-active-compiler-path/lib>")
find_path(CUSTOMUTILS_INCLUDE_DIR custom_utils.h PATHS "<your-active-compiler-path/include>")

# Include directories
include_directories(${CUSTOMUTILS_INCLUDE_DIR})

# Source files
set(SOURCES main.c)

# Create the executable
add_executable(program ${SOURCES})

# Link the customutils library
target_link_libraries(program ${CUSTOMUTILS_LIB})
```

## C file
```c
#include <custom_utils.h> // always make sure to include
// or #include "custom_utils.h"

int main()
{
    // example usage
    int num;

    fetch(&num, "[+] Please input value: ", 0, 5, TYPE_LD);

    printf("%d\n", num);

    return 0;
}
```

## Symbol Notation

To enhance the clarity of the output in your program, we use the following symbols:

- `[+]`: Program output - This symbol is used for general messages from the program, indicating successful actions or confirmations.
- `[-]`: User input prompt - This symbol precedes messages that expect user input.
- `[*]`: Debug output - This symbol is used for debugging information that may help in diagnosing issues during development.
- `[!]`: Error messages - This symbol indicates that an error has occurred, providing details about what went wrong.
- `[?]`: Warning messages - This symbol is used to flag potential issues that do not stop the program but should be noted.

## Notes

This library uses the C17 standard for C.
This library uses the GNU++17 standard for C++.

**WARNING:** Make sure that there are no conflicting names when using this library.

## Compatibility

The static library `libutils.a` is compatible with Windows, macOS, and Linux by default. However, please note that the library may not work as intended on any operating system without some adjustments to the paths - it depends on what compiler you're using.
