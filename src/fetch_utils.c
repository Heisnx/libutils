/*
 * File: fetch_utils.c // Ali Allahverdiyev
 * ----------------------
 * Description:
 *      This file is filled with input-based utility functions
 *      that I plan on using for every lab task in the
 *      Programming I & Programming courses.
 * 
 * Elements:
 *      - fetch_array()
 *      - fetch_int()
 *      - fetch_dbl()
 * 
 * Version: v1.0.0
 * Date of creation: 28/10/2024
 * Last modified: 28/10/2024
 */

#include <main_utils.h>

/*
 * fetch_array()
 * ----------------------
 * Description:
 *      Reads an arr from the input stream.
 *      Stylised prompting included.
 * 
* Warning:
 *      [%d]/[%d] is always printed after the prompt
 *      to indicate the amount of remaining elements.
 */
int *fetch_array(int arr[], int arr_len, const char* prompt)
{
    char buffer[BUFFER];

    for (int i = 0; i < arr_len; ++i)
    {
        snprintf(buffer, sizeof(buffer), "%s [%d]/[%d]", prompt, i + 1, arr_len);
        fetch_int(&arr[i], buffer, MIN, MAX);
    }
    
    return arr;
}

/*
 * fetch_int()
 * ----------------------
 * Description:
 *      Prompts the user before reading with fgets().
 *      The read value is converted into a long int (ld).
 */
int fetch_int(int *input, const char *prompt, int min, int max)
{
    char buffer[BUFFER];

    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            char *endptr;
            errno = 0;
            long value = strtol(buffer, &endptr, 10);

            // Check for valid input and range
            if (endptr == buffer || *endptr != '\n')
            {
                fputs("[!] Invalid input (non-integer or extra characters)\n", stderr);
                print_separator();
            }
            else if (errno == ERANGE)
            {
                fputs("[!] Input out of range\n", stderr);
                print_separator();
            }
            else if (value < min || value > max)
            {
                printf("[!] Please input a value between %d and %d\n", min, max);
                print_separator();
            }
            else
            {
                *input = (int)value; // Store the valid value
                return *input;       // return the converted value as an integer
            }
        }
        else
        {
            fputs("[!] Error handling input\n", stderr);
            print_separator();
        }
    }
}

/*
 * fetch_dbl()
 * ----------------------
 * Description:
 *      Prompts the user before reading with fgets().
 *      The read value is converted into a long float (lf).
 */
double fetch_dbl(double *input, const char *prompt, double min, double max)
{
    char buffer[BUFFER];

    while (1)
    {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            char *endptr;
            errno = 0;
            double value = strtod(buffer, &endptr);

            // Check for valid input and range
            if (endptr == buffer || *endptr != '\n')
            {
                fputs("[!] Invalid input (non-integer or extra characters)\n", stderr);
                print_separator();
            }
            else if (errno == ERANGE)
            {
                fputs("[!] Input out of range\n", stderr);
                print_separator();
            }
            else if (value < min || value > max)
            {
                printf("[!] Please input a value between %.2lf and %.2lf\n", min, max);
                print_separator();
            }
            else
            {
                *input = (double)value;
                return *input;
            }
        }
        else
        {
            fputs("[!] Error handling input\n", stderr);
            print_separator();
        }
    }
}