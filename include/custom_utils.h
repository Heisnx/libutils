/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : custom_utils.h
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 12/11/2024
 * Version      : v1.2.2
 * License      : MIT
 * 
 * Description  :
 *      This is the main file of the library.
 *      It contains everything used in every source file.
 * 
 */

#ifndef CUSTOM_UTILS_H
#define CUSTOM_UTILS_H

/* [ Libraries ] */
#include <stdio.h>              // to use the input stream
#include <stdlib.h>             // to convert values from string to long integer and double
#include <errno.h>              // to detect range errors in the fetch functions
#include <stdbool.h>            // to identify whether the required value is int or double in fetch_value()
#include <string.h>             // to deal with string logic in fetch_string()
#include <stdarg.h>             // to use va_list
#include <unistd.h>             // isatty() & fileno()
// #include <io.h>              // isatty() on some Windows OS
// #include <fcntl.h>           // fileno() on some Windows OS

/*
 * [INFO]: The full description of each function will be present
 * within the header only - the function definitions in the source files
 * will only have a shortened description for code clarity.
 */

/* [ Macros ]  */

#define RESET "\x1b[0m" // reset colour and bold text
#define BOLD "\x1b[1m"  // bold text
#define BUFFER (512)    // buffer limit

/* [ Structs ] */

typedef struct 
{
    const char *fg_color;
    const char *bg_color;
} Color;

/* [ Enums ] */

/* This enum is used by two headers, so it's positioned here. */
typedef enum
{
    TYPE_INT,           // [ int ]              [ 2/4 bytes ]
    TYPE_LONG,          // [ long int ]         [ 8 bytes ]
    TYPE_LONG_LONG,     // [ long long int ]    [ 8 bytes ] 
    TYPE_FLOAT,         // [ float ]            [ 4 bytes ]
    TYPE_DOUBLE,        // [ double ]           [ 8 bytes ]
} Fetch_Type;

/* [ Colours ] */

extern const Color RED;
extern const Color GREEN;
extern const Color YELLOW;
extern const Color BLUE;
extern const Color MAGENTA;
extern const Color CYAN;

/* [ Arrays ] */

/*
 * type_sizes[]
 * ----------------------
 * Description:
 *      The byte size of different data types.
 * 
 * Notes:
 *      - This generic macro is kept in the main header as it can be used independently.
 *      - Octals and hexadecimals in code get interpreted as integers - long long.
 *      - Defaults to zero for easier debugging.
 */
extern size_t type_sizes[];

/* [ Inline Functions ] */

/*
 * Function: is_empty_input
 * ----------------------
 * Description:
 *      Checks whether the buffer is empty or a newline character. 
 */
static inline bool is_empty(const char *buffer) 
{
    return buffer[0] == '\n';
}

/*
 * Function: validate_input()
 * ---------------------------
 * Description:
 *      Validates numerical values based on errno, endptr, and range.
 */
static inline bool validate(const char *endptr, double input, double min, double max)
{
    if (errno != 0 || *endptr != '\n') 
        return true;
    
    if (input < min || input > max)
        return true;
    
    return false;
}

#endif // CUSTOM_UTILS_H

/* custom_utils.h */