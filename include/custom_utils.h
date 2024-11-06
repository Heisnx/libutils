/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : custom_utils.h
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 05/11/2024
 * Version      : v1.2.0
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

/*
 * [INFO]: The full description of each function will be present
 * within the header only - the function definitions in the source files
 * will only have a shortened description for code clarity.
 */

/* [ Macros ]  */
#define BUFFER (256)                // buffer limit
#define MINLIM12 (-2048)            // the 12 bit lower bound
#define MAXLIM12 (2047)             // the 12 bit upper bound
#define MINLIM16 (-32768)           // the 16 bit lower bound
#define MAXLIM16 (32767)            // the 16 bit upper bound
#define MINLIM32 (-2147483648)      // the 32 bit lower bound
#define MAXLIM32 (2147483647)       // the 32 bit upper bound

/* [ Colours ] */
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define RED         "\033[1;31m"
#define GREEN       "\033[1;32m"
#define BLUE        "\033[1;34m"
#define YELLOW      "\033[1;33m"

/* [ Enums & Structs ] */
typedef enum
{
    TYPE_LD,    // [ long int ]         [ 8 bytes ]
    TYPE_LLD,   // [ long long int ]    [ 8 bytes ] 
    TYPE_O,     // [ octal ]            [ 4/8 bytes ]
    TYPE_X,     // [ hexadecimal ]      [ 4/8 bytes ]
    TYPE_F,     // [ float ]            [ 4 bytes ]
    TYPE_LF,    // [ double ]           [ 8 bytes ]  
    TYPE_S      // [ string ]           [ x bytes ]
} Fetch_Type;

typedef enum
{
    DASH,       // [---] divider out of dashes
    EQUALS,     // [===] divider out of equals signs
    ASTERISK,   // [***] divider out of asterisks
    TILDE,      // [~~~] divider out of tildes
    HASH,       // [###] divider out of hashes
    UNDERSCORE, // [___] divider out of underscores
} Char_Type;

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