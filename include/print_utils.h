/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : print_utils.h
 * Author       : Heisnx (c)
 * Date Created : 05/10/2024
 * Last Modified: 05/11/2024
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
 * Function: print_number_array()
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
void print_number_array(void *arr, int len, const char *msg, Fetch_Type type);

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
 * Function: print_warning()
 * ----------------------
 * Description:
 *      Prints out an warning message with whatever amount of arguments.
 * 
* Arguments:
 *      - format: A string containing the format specification for the warning message.
 *      - ...   : Additional arguments that match the format placeholders (e.g., integers, floats, strings).
 * 
 * Return: -
 */
void print_warning(const char *format, ...);

/*
 * Function: print_error()
 * ----------------------
 * Description:
 *      Prints out an error message with whatever amount of arguments.
 * 
* Arguments:
 *      - format: A string containing the format specification for the error message.
 *      - ...   : Additional arguments that match the format placeholders (e.g., integers, floats, strings).
 * 
 * Return: -
 */
void print_error(const char *format, ...);

/*
 * Function: print_debug()
 * ----------------------
 * Description:
 *      Prints out a debug message with whatever amount of arguments.
 * 
 * Arguments:
 *      - format: A string containing the format specification for the debug message.
 *      - ...   : Additional arguments that match the format placeholders (e.g., integers, floats, strings).
 * 
 * Return: -
 */
void print_debug(const char *format, ...);

#endif // PRINT_UTILS_H

/* print_utils.h */