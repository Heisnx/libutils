/*
 * [ Utility ]
 * ----------------------
 * File Name    : utils.h
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 04/11/2024
 * Version      : v1.1.0
 * License      : MIT
 * 
 * Description  :
 *      This is the main file of the library.
 *      It contains everything used in every source file.
 *
 * Notes:
 *      - Possible to splinter utils.h into multiple headers    [Likely].
 *      - Might expand on array fetching further                [Unlikely].
 * 
 */

#ifndef CUSTOM_UTILS_H
#define CUSTOM_UTILS_H

/* [ Libraries ] */
#include <stdio.h>              // to use the input stream
#include <stdlib.h>             // to convert values from string to long integer and double
#include <errno.h>              // to detect range errors in the fetch functions
#include <stdbool.h>            // to identify whether the required value is int or double in fetch_value()
#include <string.h>             // to deal with string logic in fetch()

/* [ Macros ]  */
#define BUFFER (256)                // buffer limit
#define MINLIM12 (-2048)            // the 12 bit lower bound
#define MAXLIM12 (2047)             // the 12 bit upper bound
#define MINLIM16 (-32768)           // the 16 bit lower bound
#define MAXLIM16 (32767)            // the 16 bit upper bound
#define MINLIM32 (-2147483648)      // the 32 bit lower bound
#define MAXLIM32 (2147483647)       // the 32 bit upper bound

/* [ Enums & Structs ] */
typedef enum
{
    TYPE_LD,    // [ long int ]         [ 8 bytes ]
    TYPE_LLD,   // [ long long int ]    [ 8 bytes ] 
    TYPE_O,     // [ octal ]            [ 4/8 bytes ]
    TYPE_X,     // [ hexadecimal ]      [ 4/8 bytes ]
    TYPE_F,     // [ float ]            [ 4 bytes ]
    TYPE_LF,    // [ double ]           [ 8 bytes ]  
    TYPE_C,     // [ char ]             [ 1 byte ]
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
    return (errno == 0 && *endptr == '\n' && input >= min && input <= max);
}

/* [ Functions ] */

/*
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|                        print_utils.c                        |
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/

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
void print_array(const int arr[], int arr_len, const char* msg);

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
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|                        sort_utils.c                         |
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/

/*
 * Function: partition()
 * ----------------------
 * Description:
 *      Helper function for quick_sort(). Partitions the array around a pivot
 *      and returns the pivot index. All elements less than the pivot are 
 *      placed to its left, and all greater elements to its right.
 *
 * Arguments:
 *      - arr[]   : Array of integers to partition.
 *      - low     : Starting index of the partition.
 *      - high    : Ending index and pivot position.
 *
 * Return:
 *      The final position of the pivot in the array.
 */
int partition(int arr[], int low, int high);

/*
 * Function: insertion_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using 
 *      insertion sort. The array is built up one element at a time
 *      by moving larger elements to the right to make space for
 *      each insertion.
 * 
 * Arguments:
 *      - arr[]   : Array of integers to sort.
 *      - arr_len : Length of the array.
 * 
 * Returns: -
 */
void insertion_sort(int arr[], int arr_len);

/*
 * Function: quick_sort()
 * ----------------------
 * Description:
 *      Recursively sorts the elements of an array in ascending order 
 *      using the quick sort algorithm. It divides the array into two 
 *      partitions and recursively sorts each partition.
 *
 * Arguments:
 *      - arr[]   : Array of integers to sort.
 *      - low     : Starting index of the partition.
 *      - high    : Ending index and pivot position.
 * 
 * Returns: -
 */
void quick_sort(int arr[], int low, int high);

/*
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|                        fetch_utils.c                        |
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/

/*
 * Function: fetch_array()
 * ----------------------
 * Description:
 *      Reads an array of integers or doubles from the input stream based on is_int flag.
 *      Provides stylized prompting, including element count.
 *
 * Arguments:
 *      arr         : Void pointer to an integer or double array.
 *      len         : Number of elements in the array.
 *      prompt      : Prompt message to display for each element.
 *      type        : The data type that is expected.
 *      disp_cnt    : The option to display counter.
 *      min         : Minimal argument accepted.
 *      max         : Maximal argument accepted.
 * 
 * Return: -
 */
void fetch_array(void *arr, int len, const char *prompt, Fetch_Type type, bool disp_cnt, double min, double max);

/*
 * Function: fetch()
 * ----------------------
 * Description:
 *      Outputs prompt, reads input using fgets(),
 *      converts it to selected type, and validates 
 *      the input.
 * 
 * Arguments:
 *      - input : The variable where we store the input.
 *      - prompt: The prompt displayed to the user.
 *      - min   : The minimal accepted value [NUMBER ONLY].
 *      - max   : The maximal accepcted value [NUMBER ONLY].
 *      - type  : The type of the final value.
 * 
 * Return: -
 * 
 * Warning:
 *      - For TYPE_C, only the first value of the buffer will be read,
 *        regardless of there being other values in buffer.
 */
void fetch(void *input, const char *prompt, double min, double max, Fetch_Type type);

#endif // CUSTOM_UTILS_H

/* custom_utils.h */