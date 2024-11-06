# Changelog

## [v1.0.0] - 29/10/2024 [Initial]
### Changes
- **`custom_utils.h`**
    - Added `BUFFER` macro (100 bytes).
    - Added `MIN` and `MAX` macros (-1,000,000,000 and 1,000,000,000).
    - Included references to `stdio.h`, `stdlib.h`, `errno.h`, and `stdbool.h`.

- **`fetch_utils.c`**
    - Introduced `fetch_int()` to safely fetch integers.
    - Introduced `fetch_double()` to safely fetch doubles.
    - Added `fetch_array()` for filling integer arrays.

- **`sort_utils.c`**
    - Implemented `bubble_sort()` for integer arrays.
    - Implemented `insertion_sort()` for integer arrays.
    - Introduced `quick_sort()` and `partition()` for integer arrays.

- **`print_utils.c`**
    - Added `print_separator()` to print 100 equals signs.
    - Introduced `print_array()` to print integer arrays.

## [v1.0.1] - 29/10/2024 [Patch]
### Changes
- **Global**
    - Added repository to GitHub.
    - Library linking issues resolved.
    - Minor logic fixes in functions.

## [v1.0.2] - 30/10/2024 [Patch]
### Changes
- **`custom_utils.h`**
    - Updated `MIN` and `MAX` to -1000 and 1000.
    - Increased `BUFFER` size to 128 bytes.

- **`fetch_utils.c`**
    - Introduced `fetch_number()` to read both integer and double values.
    - Updated `fetch_array()` to align with `fetch_number()` functionality.
    - Removed `fetch_int()`
    - Removed `fetch_double()`

- **`sort_utils.c`**
    - Removed `bubble_sort()`.

## [v1.0.3] - 30/10/2024 [Patch]
### Changes
- **Global**
    - Added compatibility for Unix-based OS (macOS & Linux).
    - Updated usage instructions.
    - Minor fixes applied.

## [v1.1.0] - 04/11/2024 [Update]
### Changes
- **Global**
    - Transitioned from Makefile to CMake for building and linking.
    - Updated installation instructions due to the switch to CMake.
    - Revised `README.md`.

- **`custom_utils.h`**
    - Increased `BUFFER` size to 256 bytes.
    - Removed `MIN` and `MAX` macros.
    - Introduced `MINLIM12`, `MAXLIM12`, `MINLIM16`, `MAXLIM16`, `MINLIM32`, and `MAXLIM32` for bit limits.
    - Added reference to `string.h` for `fetch_utils.c` functionality.
    - Introduced `Fetch_Type` enum (8 entries).
    - Introduced `Char_Type` enum (6 entries).
    - Added two inline static bool functions: `is_empty()` and `validate()`.
    - Updated descriptions for some functions.

- **`fetch_utils.c`**
    - Added `fetch()` to read 8 different data types with validation.
    - Removed `fetch_number()` from v1.0.2.
    - Modified `fetch_array()` to be compatible with `fetch()`.

- **`print_utils.c`**
    - Introduced `print_progress_bar()` with customization options.
    - Renamed `print_separator()` to `print_divider()` and added customization.

- **`sort_utils.c`**
    - Reintroduced `bubble_sort()` from v1.0.1.
    - Added `merge()` and `merge_sort()` for sorting algorithms.

## [v1.1.1] - 05/11/2024 [Patch]
### Changes
- **`fetch_utils.c`**
    - Readded `fetch_number()`, replacing `fetch()`.
    - Improved `fetch_number()` logic (compared to `fetch()`).
    - Added new `fetch_string()` function.
    - Changed `fetch_array()` to `fetch_number_array()`

- **`print_utils.c`**
    - Changed `print_array()` to `print_number_array()`
    that can print arrays of the same data types as `fetch_number()`
    except octals and hexadecimals.

## [v1.2.0] - 05/11/2024 [Update]
### Changes
- **Global**
    - Changed to modular library with header files:
        - **`fetch_utils.h`
        - **`print_utils.h`
        - **`sort_utils.h`
    - Changed `README.md` instructions to reflect on this change.
    - Changed library to package within CMake.
    - Modified installation guide.

- **`custom_utils.h`**
    - Added colour macros:
        - Red;
        - Blue;
        - Yellow;
        - Green;
        - Bold;
        - Reset (reset colour).

- **`print_utils.h`**
    - New function `print_warning()`.
    - New function `print_error()`.
    - Enhanced `print_number_array()`.

- **`fetch_utils.c`**
    - Fixed `fetch_number()` logic to properly handle non-numeric inputs.
    - Fixed `fetch_number()` conversion logic (again).

## [v1.2.1] - 05/11/2024 [Patch]
### Changes
- **Global**
    - Minor tweaks.

- **`print_utils.h`**
    - New function `print_debug()`.

### Considerations
- None as of v1.2.0

### Warnings
Users of older versions should review this changelog for potential compatibility issues before upgrading, especially regarding function removals and significant changes in functionality.

From version 1.2.0, the library became modular, so make sure to include the specific headers based on your usage - including custom_utils.h
no longer works!
