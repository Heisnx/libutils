#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>       // to use the input stream
#include <stdlib.h>      // to convert values from string to long integer and double
#include <errno.h>       // to detect range errors in the fetch functions
#include <stdbool.h>     // to identify whether the required value is int or double in fetch_value()

#define BUFFER 100      // buffer limit
#define MIN -1000000000 // the absolute minimum value a user can input into the fetch functions [-1B]
#define MAX 1000000000  // the absolute maximum value a user can input into the fetch functions [+1B]

/*
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|                        print_utils.c                        |
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/

/*
 * print_separator()
 * ----------------------
 * Description:
 *      Prints out a separator made out of equal signs.
 *
 * Arguments:
 *      - [void] this function has no arguments.
 *
 * Returns:
 *      - [void] this function has no return type.
 */
void print_separator(void);

/*
 * print_array()
 * ----------------------
 * Description:
 *      Prints the elements of an array in a formatted list.
 *
 * Arguments:
 *      - [int] arr[]       : Array to be printed.
 *      - [string] prompt   : The prompt shown to the user.
 *      - [int] arr_len     : Length of the array.
 *
 * Returns:
 *      - [void] This function has no return type.
 * 
 * Warning:
 *      - A colon sign is put after the prompt.
 */
void print_array(const int arr[], const char* prompt, int arr_len);

/*
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|                        sort_utils.c                         |
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/

/*
 * partition()
 * ----------------------
 * Description:
 *      Helper function for quick_sort(). Partitions the array around a pivot
 *      and returns the pivot index. All elements less than the pivot are 
 *      placed to its left, and all greater elements to its right.
 *
 * Arguments:
 *      - [int] arr[]   : Array of integers to partition.
 *      - [int] low     : Starting index of the partition.
 *      - [int] high    : Ending index and pivot position.
 *
 * Return:
 *      - [int] The final position of the pivot in the array.
 */
int partition(int arr[], int low, int high);

/*
 * bubble_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using
 *      the bubble sort algorithm. The largest elements bubble
 *      to the end of the array after each pass.
 *
 * Arguments:
 *      - [int] arr[]   : Array of integers to sort.
 *      - [int] arr_len : Length of the array.
 * 
 * Returns:
 *      - [void] This function has no return type.
 */
void bubble_sort(int arr[], int arr_len);

/*
 * insertion_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using 
 *      insertion sort. The array is built up one element at a time
 *      by moving larger elements to the right to make space for
 *      each insertion.
 * 
 * Arguments:
 *      - [int] arr[]   : Array of integers to sort.
 *      - [int] arr_len : Length of the array.
 * 
 * Returns:
 *      - [void] This function has no return type.
 */
void insertion_sort(int arr[], int arr_len);

/*
 * quick_sort()
 * ----------------------
 * Description:
 *      Recursively sorts the elements of an array in ascending order 
 *      using the quick sort algorithm. It divides the array into two 
 *      partitions and recursively sorts each partition.
 *
 * Arguments:
 *      - [int] arr[]   : Array of integers to sort.
 *      - [int] low     : Starting index of the partition.
 *      - [int] high    : Ending index and pivot position.
 * 
 * Returns:
 *      - [void] This function has no return type.
 */
void quick_sort(int arr[], int low, int high);

/*
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
|                        fetch_utils.c                        |
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
*/

/*
 * fetch_array()
 * ----------------------
 * Description:
 *      Reads an array from the input stream.
 *      Stylised prompting included.
 *
 * Arguments:
 *      - [int array] arra      : the array that gets filled.
 *      - [int] arr_len         : the length of the array.
 *      - [string] prompt       : the prompt given to the user
 *
 * Return:
 *      - [int array] The resulting array
 * 
 * Warning:
 *      [%d]/[%d] is always printed after the prompt
 *      to indicate the amount of remaining elements.
 */
int *fetch_array(int array[], int arr_len, const char* prompt);

/*
 * fetch_int()
 * ----------------------
 * Description:
 *      Prompts the user before reading with fgets().
 *      The read value is converted into a long int (ld).
 *
 * Arguments:
 *      - [int]  input   : pointer to the integer variable to store the validated input.
 *      - [string] prompt  : the message prompt to the user.
 *      - [double]  min     : the minimum allowed value.
 *      - [double]  max     : the maximum allowed value.
 *
 * Return:
 *      - [int] The converted integer value.
 */
int fetch_int(int *input, const char *prompt, int min, int max);

/*
 * fetch_double()
 * ----------------------
 * Description:
 *      Prompts the user before reading with fgets().
 *      The read value is converted into a long float (lf).
 *
 * Arguments:
 *      - [double]  input   : pointer to the integer variable to store the validated input.
 *      - [string]   prompt  : the message prompt to the user.
 *      - [double]  min     : the minimum allowed value.
 *      - [double]  max     : the maximum allowed value.
 *
 * Return:
 *      - [double] The converted long float (double) value.
 */
double fetch_dbl(double *input, const char *prompt, double min, double max);

#endif // UTILS_H