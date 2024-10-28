/*
 * File: print_utils.c // Ali Allahverdiyev
 * ----------------------
 * Description:
 *      This file is filled with print-based utility functions
 *      that I plan on using for every lab task in the
 *      Programming I & Programming courses.
 * 
 * Elements:
 *      - print_separator()
 * 
 * Version: v1.0.0
 * Date of creation: 28/10/2024
 * Last modified: 28/10/2024
 */

#include <main_utils.h>

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
 * 
 * Warning:
 *      - A colon sign is put after the prompt.
 */
void print_array(const int arr[], const char* prompt, int arr_len)
{
    printf("%s: ", prompt);
    printf("{ ");
    
    for(int i = 0; i < arr_len; ++i)
    {
        printf("%d", arr[i]);

        if (i < arr_len - 1)
            printf(", ");
    }

    printf(" }");
}