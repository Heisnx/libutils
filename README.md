# Utility Functions for C

[![Version](https://img.shields.io/github/v/release/Heisnx/libutils.svg)](https://github.com/Heisnx/libutils/releases)
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

**WARNING:** Before installation, ensure that you have CMake installed on your machine and a valid C/C++ compiler.

**WARNING:** If you wish to install this library into system directories (like `Program Files` or `/usr/local`), you may need administrator permissions.

**NOTE:** Reinstall the library will always replace the old files.

**TIP:** It’s recommended to proceed with this guide using Visual Studio Code or any CMake-compatible IDE.
 
To integrate the `libutils` library into your system, follow these steps:

1. Clone this repository to your local machine.

```bash
git clone https://github.com/Heisnx/libutils.git
cd libutils
```

2. Create a `build` directory within the root directory of this repository:

```bash
mkdir build
cd build
```

3. Within the build directory, you need to configure CMake. This is usually available as an option in 
Visual Studio Code, but if not, then you can proceed with:

```bash
cmake ..
cmake --build .
cmake --install . --prefix "<your-active-compiler-path>"
```

4. However, if you wish to install this library to your program files or local files, you can run the install command without specifying the prefix;
just note that it may require administrator permissions, so you may want to run terminal as admin (if it's possible):

```bash
cmake --install .
```

## Usage

**WARNING:** Always replace `"<your-active-compiler-path/lib>"` and `"<your-active-compiler-path/include>"` with the actual paths where the library and header files are installed.

**WARNING:** `fetch_utils.h` already includes `print_utils.h`, so there is no need to re-include it again in your projects.

**INFO:** Since version 1.2.0, this library became modular, so you may want to include the specific header of the functions you're going to use.

Once the library is installed, you can start using it in your C/C++ projects. Below are the steps to integrate the `libcustomutils` library into your own project:

1. Start by including the needed header files:

```c
#include <fetch_utils.h>    // for fetch utility functions
#include <print_utils.h>    // for print utility functions
#include <sort_utils.h>     // for sorting utility functions
```

2. Then, link against the library and make sure to replace `/path/to/libutils` with the proper path that you installed the library to:

```cmake
# In your project's CMakeLists.txt

# Set the path to your installed library (if not installed globally)
# set(LIBUTILS_PATH "/path/to/libutils")

# Link the library
target_link_libraries(your_target PRIVATE libutils)
```

3. If you're only using Makefile, you can still link against the library as shown in this template Makefile:

```makefile
# Path to your libutils installation
LIBUTILS_PATH = /path/to/libutils

# Compiler and flags
CC = gcc
CFLAGS = -Wall -std=c99

# Include the path to the libutils headers
INCLUDE_PATH = $(LIBUTILS_PATH)/include

# Path to libutils library (libutils.a or libutils.so)
LIBRARY_PATH = $(LIBUTILS_PATH)/lib

# Library name (assuming static library, if it's shared, use -lutils)
LIBRARY = -lutils

# Sources and objects
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Executable output
EXEC = my_program

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) -L$(LIBRARY_PATH) $(LIBRARY)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_PATH) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
```

4. After that, you're free to use the library:

```c
#include <fetch_utils.h>
// note that I don't need to include print_utils.h since fetch_utils.h already has it included

int main(int argc, char **argv)
{
    int num;
    int arr[5] = { 1, 2, 3, 5, 4 };

    fetch_number(&num, "[-] Please input a number: ", 0, 100, TYPE_LD); // gets integer from user

    printf("%d\n", num);
    print_number_array(arr, 5, "[+] Array elements:", TYPE_LD);

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
**WARNING:** Since version 1.2.0, the library became modular, so make sure to change the inclusions.

## Compatibility

The static library `libcustomutils.a` is compatible with Windows, macOS, and Linux by default. However, please note that the library may not work as intended on any operating system without some adjustments to the paths - it depends on what compiler you're using.