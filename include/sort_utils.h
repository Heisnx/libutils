/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : sort_utils.h
 * Author       : Heisnx (c)
 * Date Created : 04/11/2024
 * Last Modified: 12/11/2024
 * 
 * Description  :
 *      This file contains all of the declarations for
 *      sort_utils.c specifically.
 */

#ifndef SORT_UTILS_H
#define SORT_UTILS_H

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
 * merge()
 * ----------------------
 * Description:
 *      Merges two subarrays of arr[] into a single sorted array.
 *      The first subarray is arr[l..m] and the second subarray is arr[m+1..r].
 * 
 * Arguments:
 *      - arr[]   : Array of integers containing the subarrays to merge.
 *      - l       : Starting index of the first subarray.
 *      - m       : Ending index of the first subarray and the midpoint.
 *      - r       : Ending index of the second subarray.
 * 
 * Return: -
 */
void merge(int arr[], int l, int m, int r);

/*
 * bubble_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using 
 *      bubble sort. Repeatedly steps through the list, compares
 *      adjacent elements, and swaps them if they are in the wrong order.
 *
 * Arguments:
 *      - arr[]   : Array of integers to sort.
 *      - arr_len : Length of the array.
 * 
 * Returns: -
 */
void bubble_sort(int arr[], int arr_len);

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
 * merge_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using 
 *      merge sort. Divides the array into halves, recursively sorts each half,
 *      and merges them back together.
 * 
 * Arguments:
 *      - arr[]   : Array of integers to sort.
 *      - l       : Starting index of the array (or subarray).
 *      - r       : Ending index of the array (or subarray).
 * 
 * Return: -
 */
void merge_sort(int arr[], int l, int r);

#endif // SORT_UTILS_H

/* sort_utils.h */