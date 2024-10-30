/*
 * [ Utility ]
 * ----------------------
 * File Name    : utils.h
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 30/10/2024
 * Version      : v1.0.3
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

#ifndef UTILS_H
#define UTILS_H

/* [ Libraries ] */
#include <stdio.h>       // to use the input stream
#include <stdlib.h>      // to convert values from string to long integer and double
#include <errno.h>       // to detect range errors in the fetch functions
#include <stdbool.h>     // to identify whether the required value is int or double in fetch_value()

#define BUFFER 128      // buffer limit
#define MIN -1000       // the absolute minimum value a user can input into the fetch functions [-1B]
#define MAX 1000        // the absolute maximum value a user can input into the fetch functions [+1B]

/*
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|                        print_utils.c                        |
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/

/*
 * Function: print_separator()
 * ----------------------
 * Description:
 *      Prints out a separator made out of equal signs.
 *
 * Arguments: -
 * Returns: -
 */
void print_separator(void);

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
 * Parameters:
 *      arr     : Void pointer to an integer or double array.
 *      len     : Number of elements in the array.
 *      prompt  : Prompt message to display for each element.
 *      is_int  : Boolean flag indicating if the array is of integers (true) or doubles (false).
 *
 * Warning:
 *      - [%d]/[%d] is always printed after the prompt to indicate the amount of remaining elements.
 *      - Ensure 'arr' or 'input' points to either 'int' or 'double' based on 'is_int'.
 */
void fetch_array(void *arr, int len, const char *prompt, bool is_int);

/*
 * Function: fetch_number()
 * ----------------------
 * Description:
 *      Prompts the user with a given message, reads input using fgets(),
 *      and converts it to either an integer or double based on the is_int flag.
 *      Validates the input within the provided range.
 *
 * Parameters:
 *      - input   : Void pointer to store either an integer or double.
 *      - prompt  : Prompt message to display before reading input.
 *      - min     : Minimum acceptable value (as double for compatibility).
 *      - max     : Maximum acceptable value (as double for compatibility).
 *      - is_int  : Flag indicating if the input should be an integer (true) or double (false).
 *
 * Returns:
 *      0 on success & -1 on error.
 * 
 * Warnings:
 *      - Ensure 'arr' or 'input' points to either 'int' or 'double' based on 'is_int'.
 */
int fetch_number(void *input, const char *prompt, double min, double max, bool is_int);

#endif // UTILS_H

/* utils.h */