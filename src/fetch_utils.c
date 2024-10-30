/*
 * [ Utility ]
 * ----------------------
 * File Name    : fetch_utils.c
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 30/10/2024
 * 
 * Description:
 *      This source file contains functions oriented
 *      at receiving user input.
 *
 * Warnings:
 *      - No notable warnings as of v1.0.2
 */

/* [ Headers ] */
#include <custom_utils.h>

/*
 * fetch_array()
 * ----------------------
 * Description:
 *      Reads an array of integers or doubles from the input stream based on is_int flag.
 *      Provides stylized prompting, including element count.
 *
 * Warning:
 *      [%d]/[%d] is always printed after the prompt
 *      to indicate the amount of remaining elements.
 */
void fetch_array(void *arr, int len, const char *prompt, bool is_int)
{
    char buffer[BUFFER];

    /* 1. Start the loop to ask the user for every element. */
    for (int i = 0; i < len; ++i) 
    {
        /* 2. Create the prompt. */
        snprintf(buffer, sizeof(buffer), "%s [%d]/[%d]: ", prompt, i + 1, len);

        /* 3. If integer is expected, explicitly casts to integer. */
        if (is_int) 
            fetch_number(&((int*)arr)[i], buffer, MIN, MAX, true);

        /* 4. Otherwise, casts to double. */
        else
            fetch_number(&((double*)arr)[i], buffer, (double)MIN, (double)MAX, false);
    }
}

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
 */
int fetch_number(void *input, const char *prompt, double min, double max, bool is_int) 
{
    char buffer[BUFFER];

    while (true) 
    {
        /* 1. Output user prompt. */
        printf("%s", prompt);

        /* 2. Uses fgets() to handle input. */
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) 
        {
            char *endptr;
            errno = 0;

            /* 3a. If an integer is expected, converts to long int. */
            if (is_int) 
            {
                long value = strtol(buffer, &endptr, 10);
                
                /* 4a. Checks for integer input for errors. */
                if (endptr == buffer || *endptr != '\n')
                    fputs("[!] Invalid input (non-integer or extra characters)\n", stderr);

                else if (errno == ERANGE || value < (long)min || value > (long)max)
                    printf("[!] Please input an integer between %.0f and %.0f\n", min, max);

                /* 5a. Explicitly casts the integer value to input. */
                else 
                {
                    *(int*)input = (int)value;
                    return 0;
                }
            }

            /* 3b. If a double is expected, converts to long float (double). */
            else 
            {
                double value = strtod(buffer, &endptr);

                /* 4a. Checks for double input for errors. */
                if (endptr == buffer || *endptr != '\n')
                    fputs("[!] Invalid input (non-numeric or extra characters)\n", stderr);

                else if (errno == ERANGE || value < min || value > max)
                    printf("[!] Please input a value between %.2lf and %.2lf\n", min, max);

                /* 5a. Explicitly casts the double value to input. */
                else 
                {
                    *(double*)input = value;
                    return 0;
                }
            }
        }

        /* 6. If input is unknown, it exits without processing further. */
        else 
        {
            fputs("[!] Error handling input\n", stderr);
            return -1;
        }
    }
}