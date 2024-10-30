# Utility Functions for C

[![Version](https://img.shields.io/badge/version-v1.0.3-red.svg)](https://shields.io/)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://choosealicense.com/)

A collection of utility functions for C programming, designed to simplify common tasks such as printing, sorting, and fetching user input. This small project is still a work in progress.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Function Types](#function-types)
- [Warnings](#warnings)
- [Compatibility](#compatibility)

## Features

- **Printing Functions**: Easily print arrays and separators.
- **Sorting Algorithms**: Implementations of bubble sort, insertion sort, and quick sort.
- **Input Handling**: Fetch integers and doubles with input validation.
- **Array Handling**: Read arrays from user input with styled prompts.

## Installation

You can integrate the utility functions into your C projects by including the `custom_utils.h` header file. The functions are packaged in a static library (`libutils.a`), which gets installed into the `ucrt64/lib` and `ucrt64/include` folders. 

To compile the library, you will need to use the provided `Makefile`. Depending on your operating system, you may want to modify some parts of the `Makefile` for better compatibility. If you wish to change the installation paths, please look in the `Makefile` for configuration options.

## Usage

To integrate the library into your project, follow these steps:

1. **Update the Makefile**: Modify the Makefile according to your compiler. (GCC is the default.)
2. **Adjust Installation Paths**: Change the install paths based on your operating system. (Default is `msys64/ucrt64`.)
3. **Compile the Library**: Run the Makefile to compile the library.
4. **Set System Path**: Ensure that the directory where you installed the library is included in your system path.
5. **Create a Project Makefile**: Navigate to your project directory and create a new Makefile.
6. **Link the Library**: Use the following command in your Makefile to link the library to your project:

   ```makefile
   $(EXEC): $(OBJS)
       $(CC) $(OBJS) -o $(EXEC) -L"ucrt64/lib" -lcustomutils


## Function Types

- **Fetching functions**: Used to get information from the user.
- **Printing functions**: Used to print information.
- **Sorting functions**: Used to sort arrays and datasets.

## Notes

This library uses the C17 standard for C.
This library uses the GNU++17 standard for C++.

## Compatibility

The static library `libutils.a` is compatible with Windows, macOS, and Linux by default. However, please note that the library may not work as intended on macOS or Linux operating systems without some adjustments to the `Makefile`. This library was compiled using the `Makefile` on a Windows OS.

`libutils.a`and `custom_utils.h` get installed into the `/ucrt64/lib` and `/ucrt64/include` directories.
If you need those files somewhere else, please change the path in the makefile.
