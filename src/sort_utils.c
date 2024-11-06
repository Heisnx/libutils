/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : sort_utils.c
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 04/11/2024
 * 
 * Description:
 *      This source file contains functions oriented
 *      at sorting arrays & datasets.
 *
 * Warnings:
 *      - No notable warnings as of v1.0.2
 */

/* [ Headers ] */
#include <custom_utils.h>
#include <print_utils.h>

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

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

/*
 * merge()
 * ----------------------
 * Description:
 *      Merges two subarrays of arr[] into a single sorted array.
 *      The first subarray is arr[l..m] and the second subarray is arr[m+1..r].
 */
void merge(int arr[], int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

/*
 * bubble_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using 
 *      bubble sort. Repeatedly steps through the list, compares
 *      adjacent elements, and swaps them if they are in the wrong order.
 *
 * Notes:
 *      - Worst case performance is O(n^2), not efficient for large datasets.
 */
void bubble_sort(int arr[], int arr_len) 
{
    for (int i = 0; i < arr_len - 1; ++i) 
    {
        for (int j = 0; j < arr_len - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
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

/*
 * merge_sort()
 * ----------------------
 * Description:
 *      Sorts the elements of an array in ascending order using 
 *      merge sort. Divides the array into halves, recursively sorts each half,
 *      and merges them back together.
 */
void merge_sort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* sort_utils.c */