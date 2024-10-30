# Utility Functions for C

[![Version](https://img.shields.io/badge/version-v1.0.2-blue.svg)](https://shields.io/)
[![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](https://choosealicense.com/)

A collection of utility functions for C programming, designed to simplify common tasks such as printing, sorting, and fetching user input.
This small project is still a work in progress.

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

You can integrate the utility functions into your C projects by including the `utils.h` header file. The functions are packaged in a static library, which can be linked to your project.

## Usage

Just reference libutils.a and main_utils.h in your project.
You'll have to include main_utils.h and reference libutils.a in the compiler.

## Function Types

- Fetching functions : used to get information from the user.
- Printing functions : used to print information.
- Sorting functions  : used to sort arrays and datasets.

## Warnings

This library uses the c17 standard for C.
This library uses the gnu++17 standard for C++.

## Compatibility

May not work as intended on Mac or Linux operating systems.
This library was compiled by using Makefile on a Windows OS.