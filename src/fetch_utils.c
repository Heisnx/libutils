/*
 * [ Utility ]
 * ----------------------
 * File Name    : fetch_utils.c
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 04/11/2024
 * 
 * Description:
 *      This source file contains functions oriented
 *      at receiving user input.
 *
 * Warnings:
 *      - [v1.0.4] fetch() with TYPE_C will always read the first value
 *        of the input buffer even if the user input more than 1 character.
 */

/* [ Headers ] */
#include <custom_utils.h>

/*
 * fetch_array()
 * ----------------------
 * Description:
 *      Reads array elements with fetch().
 *      Has the option to display remaining elements.
 *      
 * Notes:
 *      - If you're expecting a character or string value,
 *        ignore the min and max arguments as they will not be used.
 *        You can set them to anything.
 */
void fetch_array(void *arr, int len, const char *prompt, Fetch_Type type, bool disp_cnt, double min, double max)
{
    char buffer[BUFFER];

    for (int i = 0; i < len; ++i) 
    {
        if (disp_cnt)
            snprintf(buffer, sizeof(buffer), "%s [%d]/[%d]: ", prompt, i + 1, len);
        else
            snprintf(buffer, sizeof(buffer), "%s", prompt);

        // Adjusting for proper typecasting based on Fetch_Type
        switch (type)
        {
            case TYPE_LD:
                fetch((int*)arr + i, buffer, min, max, type);
                break;
            case TYPE_LLD:
                fetch((long int *)arr+i, buffer, min, max, type);
                break;
            case TYPE_LF:
                fetch((double*)arr + i, buffer, min, max, type);
                break;
            case TYPE_F:
                fetch((float*)arr + i, buffer, min, max, type);
                break;
            case TYPE_C:
            case TYPE_S:
                fetch((char*)arr + i, buffer, min, max, type);
                break;
            default:
                fputs("[!] Unsupported type\n", stderr);
                break;
        }
    }
}

/*
 * Function: fetch()
 * ----------------------
 * Description:
 *      Outputs prompt, reads input using fgets(),
 *      converts it to selected type, and validates 
 *      the input.
 */
/*
 * Function: fetch()
 * ----------------------
 * Description:
 *      Outputs prompt, reads input using fgets(),
 *      converts it to the selected type, and validates 
 *      the input.
 */
void fetch(void *input, const char *prompt, double min, double max, Fetch_Type type)
{
    bool is_numeric_input = (type != TYPE_C && type != TYPE_S);
    char buffer[BUFFER];    // this is where fgets() stores the initial input

    do
    {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin))
        {
            char *endptr;
            errno = 0;

            // Checks if the input is empty
            if (is_empty(buffer)) 
            {
                fputs("[!] Input cannot be empty or a new line character\n", stderr);
                continue;   // Retries the loop
            }

            if (is_numeric_input) 
            {
                double value = 0.0; // Temporary variable to store the parsed value
                switch (type) 
                {
                    case TYPE_LD:   value = (double)strtol(buffer, &endptr, 10); break;
                    case TYPE_LLD:  value = (double)strtoll(buffer, &endptr, 10); break;
                    case TYPE_O:    value = (double)strtoul(buffer, &endptr, 8); break;
                    case TYPE_X:    value = (double)strtoul(buffer, &endptr, 16); break;
                    case TYPE_F:    value = (double)strtof(buffer, &endptr); break;
                    case TYPE_LF:   value = strtod(buffer, &endptr); break;
                    default:        continue; // Unexpected input
                }

                // Checks for conversion errors
                if (endptr == buffer || *endptr != '\n' || errno == ERANGE) 
                {
                    fputs("[!] Invalid input\n", stderr);
                    continue; // Retries the loop
                }

                // Validates range
                if (validate(endptr, value, min, max))
                {
                    // Stores the validated value in the provided input pointer
                    switch (type) {
                        case TYPE_LD:   *(long *)input = (long)value; break;
                        case TYPE_LLD:  *(long long *)input = (long long)value; break;
                        case TYPE_O:    *(unsigned long *)input = (unsigned long)value; break;
                        case TYPE_X:    *(unsigned long *)input = (unsigned long)value; break;
                        case TYPE_F:    *(float *)input = (float)value; break;
                        case TYPE_LF:   *(double *)input = value; break;
                    }
                    break; // Exits the loop on success
                }
                else
                    printf("[!] Invalid input: range is %.1lf => %.1lf\n", min, max);
            } 
            else 
            {
                if (type == TYPE_C)
                {
                    *(char *)input = buffer[0];
                    break;  // Exits the loop
                }
                else if (type == TYPE_S) 
                {
                    strncpy((char *)input, buffer, BUFFER - 1);
                    ((char *)input)[strcspn((char *)input, "\n")] = 0; // Removes the newline
                    break;  // Exits the loop on success
                }
            }
        }
        else
            fputs("[!] Error reading input\n", stderr);
    } 
    while (true);
}

/* fetch_utils.c */