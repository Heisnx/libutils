/*
 * File: sort_utils.c // Ali Allahverdiyev
 * ----------------------
 * Description:
 *      This file is filled with sorting-based utility functions
 *      that I plan on using for every lab task in the
 *      Programming I & Programming courses.
 * 
 * Elements:
 *      - partition()
 *      - bubble_sort()
 *      - insertion_sort()
 *      - quick_sort()
 * 
 * Version: v1.0.0
 * Date of creation: 28/10/2024
 * Last modified: 28/10/2024
 */

#include <main_utils.h>

/*
 * partition()
 * ----------------------
 * Description:
 *      Helper function for quick_sort(). Partitions the array around a pivot
 *      and returns the pivot index. All elements less than the pivot are 
 *      placed to its left, and all greater elements to its right.
 * 
 * Notes:
 *      - This function is part of quick_sort()
 */
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) 
    {
        if (arr[j] <= pivot) 
        {
            i++;

            /* Swap arr[j] and arr[i] */
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    /* Swap arr[i + 1] and arr[high] (pivot) */
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

/*
 * bubble_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using
 *      the bubble sort algorithm. The largest elements bubble
 *      to the end of the array after each pass.
 *
 * Notes:
 *      - Is always O(n^2), making is only useful for mostly sorted
 *      small arrays.
 */
void bubble_sort(int arr[], int arr_len) 
{
    for (int i = 0; i < arr_len - 1; ++i) 
    {
        for (int j = 0; j < arr_len - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                /* Swaps arr[j] and arr[j + 1] */
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
 * insertion_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using 
 *      insertion sort. The array is built up one element at a time
 *      by moving larger elements to the right to make space for
 *      each insertion.
 *
 * Notes:
 *      - Worst case scenario is O(n^2), making it better than bubble_sort(),
 *      but still not great for big datasets.
 */
void insertion_sort(int arr[], int arr_len) 
{
    for (int i = 1; i < arr_len; ++i) 
    {
        /* Key assignment. */
        int key = arr[i];
        int j = i - 1;

        /* Moves greater elements ahead. */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

/*
 * quick_sort()
 * ----------------------
 * Description:
 *      Recursively sorts the elements of an array in ascending order 
 *      using the quick sort algorithm. It divides the array into two 
 *      partitions and recursively sorts each partition.
 *
 * Notes:
 *      - Average case performance is O(n log n),
 *      making it suitable for large arrays and datasets.
 */
void quick_sort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        
        /* Sort separately after each partition. */
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}