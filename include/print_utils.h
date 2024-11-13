/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : print_utils.h
 * Author       : Heisnx (c)
 * Date Created : 04/11/2024
 * Last Modified: 12/11/2024
 * 
 * Description  :
 *      This file contains all of the declarations for
 *      print_utils.c specifically.
 */

#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

/* [ Headers ] */
#include <custom_utils.h>

/* 
 * [WARNING]: Your IDE might not find the file, so you might have to 
 * include that within your settings.json (if on Visual Studio Code)
 * or alter the include path to match the location of custom_utils.h
 */

/*
 * [INFO]: The full description of each function will be present
 * within the header only - the function definitions in the source files
 * will only have a shortened description for code clarity.
 */

/* [ Structs ] */

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
 * char_determ()
 * ----------------------
 * Desctiption:
 *      An inline function to assign the proper symbol.
 * 
 * Notes:
 *      - Returns a '?' if the input is unexpected.
 */
static inline char char_determ(Char_Type type) {
    switch (type) {
        case DASH:         return '-';
        case EQUALS:       return '=';
        case ASTERISK:     return '*';
        case TILDE:        return '~';
        case HASH:         return '#';
        case UNDERSCORE:   return '_';
        default:           return '?';
    }
}

/*
 * print_type_determ()
 * ----------------------
 * Desctiption:
 *      Determines the type of value to print for the arr value.
 * 
 * Notes:
 *      - Returns a '?' if the input is unexpected.
 */
static inline void print_type_determ(void* arr, Fetch_Type type, int idx)
{
    switch(type)
    {
        case TYPE_INT:          printf("%d", *((int *)arr + idx)); break;
        case TYPE_LONG:         printf("%ld", *((long int *)arr + idx)); break;
        case TYPE_LONG_LONG:    printf("%lld", *((long long int *)arr + idx)); break;
        case TYPE_FLOAT:        printf("%.2f", *((float *)arr + idx)); break;
        case TYPE_DOUBLE:       printf("%.4lf", *((double *)arr + idx)); break;
        default:                printf("\x1b[31m [ERROR] Unexpected type \x1b[0m\n");
    }
}

/* [ Functions ] */

/*
 * Function: print_divider()
 * ----------------------
 * Description:
 *      Prints out a divider made of custom size out of
 *      your preffered characters.
 *
 * Arguments:
 *      - len       : The length of the divider.
 *      - divider   : The character that will compose the divider.
 * Returns: -
 */
void print_divider(size_t len, Char_Type divider);

/*
 * Function: print_array()
 * ----------------------
 * Description:
 *      Prints the elements of an array in a formatted list.
 *
 * Arguments:
 *      - arr[]     : The array to print.
 *      - msg       : Message given to the user.
 *      - arr_len   : Length of the array.
 *
 * Returns: -
 * 
 * Notes:
 *      - Leave msg blank for no message.
 */
void print_array(void *arr, int len, const char *msg, Fetch_Type type);

/*
 * print_matrix()
 * ----------------------
 * Description:
 *      Prints the elements of a matrix in a formatted manner,
 *      by calling print_array() for each row.
 * 
 * Arguments:
 *      - matrix[][]: The matrix to print.
 *      - rows      : Number of rows.
 *      - cols      : Number of columns.
 *      - msg       : Message given to the user.
 *      - type      : Type of data to fetch.
 * 
 * Return: -
 */
void print_matrix(void **matrix, int rows, int cols, const char *msg, Fetch_Type type);

/*
 * Function: print_progress_bar()
 * ----------------------
 * Description:
 *      Prints a progress bar.
 * 
 * Arguments:
 *      - progress      : Current progress.
 *      - total         : Total progress achievable.
 *      - width         : The width of the progress bar (how large it will be).
 *      - fill_complete : The character type that will fill the filled part of the progress bar.
 *      - fill_remaining: The character type that will fill the remaining part of the progress bar.
 * 
 * Return: -
 */
void print_progress_bar(int progress, int total, int width, Char_Type fill_complete, Char_Type fill_remaining);

/*
 * Function: print_log()
 * ----------------------
 * Description:
 *      Prints out an log message with whatever amount of arguments.
 * 
* Arguments:
 *      - format: A string containing the format specification for the log message.
 *      - ...   : Additional arguments that match the format placeholders (e.g., integers, floats, strings).
 * 
 * Return: -
 */
void print_log(const char *prefix, Color color, const char *format, ...);

#endif // PRINT_UTILS_H

/* print_utils.h */