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

- **`sort_utils.h`**
    - Implemented `bubble_sort()` for integer arrays.
    - Implemented `insertion_sort()` for integer arrays.
    - Introduced `quick_sort()` and `partition()` for integer arrays.

- **`print_utils.c`**
    - Added `print_separator()` to print 100 equals signs.
    - Introduced `print_array()` to print integer arrays.

## [v1.0.1] - 29/10/2024 [Tweak]
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

- **`sort_utils.c`**
    - Removed `bubble_sort()`.

## [v1.0.3] - 30/10/2024 [Tweak]
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

### Considerations
- Future plans to split `utils.h` into multiple header files.

### Warnings
- Users of older versions should review this changelog for potential compatibility issues before upgrading, especially regarding function removals and significant changes in functionality.
