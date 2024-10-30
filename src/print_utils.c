/*
 * [ Utility ]
 * ----------------------
 * File Name    : print_utils.c
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 30/10/2024
 * 
 * Description:
 *      This source file contains functions oriented
 *      at printing elements out stylistically.
 *
 * Warnings:
 *      - No notable warnings as of v1.0.2
 */

#include <custom_utils.h>

/*
 * print_separator()
 * ----------------------
 * Description:
 *      Prints out a separator made out of equal signs.
 */
void print_separator(void)
{
    for (size_t i = 0; i < BUFFER; ++i)
        printf("=");

    printf("\n");
}

/*
 * print_array()
 * ----------------------
 * Description:
 *      Prints the elements of an array in a formatted list.
 */
void print_array(const int arr[], int len, const char* msg)
{
    printf("%s\n", msg);
    printf("\t{ ");

    for (int i = 0; i < len; ++i)
    {
        printf("%d", arr[i]);

        if (i < len - 1)
            printf(", ");
    }

    printf(" }\n");
}