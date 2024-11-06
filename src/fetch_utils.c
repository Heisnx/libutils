/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : fetch_utils.c
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 05/11/2024
 * 
 * Description:
 *      This source file contains functions oriented
 *      at receiving user input.
 */

/* [ Headers ] */
#include <custom_utils.h>
#include <fetch_utils.h>

/*
 * fetch_number_array()
 * ----------------------
 * Description:
 *      Reads array elements with fetch().
 *      Has the option to display remaining elements.
 */
void fetch_number_array(void *arr, int len, const char *prompt, Fetch_Type type, double min, double max, bool disp_cnt)
{
    char buffer[BUFFER];

    for (int i = 0; i < len; ++i) 
    {
        if (disp_cnt)
            snprintf(buffer, sizeof(buffer), "%s [%d]/[%d]: ", prompt, i + 1, len);
        else
            snprintf(buffer, sizeof(buffer), "%s", prompt);

        switch (type)
        {
            case TYPE_LD:
                fetch_number((int*)arr + i, buffer, min, max, type);
                break;
            case TYPE_LLD:
                fetch_number((long int *)arr+i, buffer, min, max, type);
                break;
            case TYPE_LF:
                fetch_number((double*)arr + i, buffer, min, max, type);
                break;
            case TYPE_F:
                fetch_number((float*)arr + i, buffer, min, max, type);
                break;
            default:
                print_warning("Unsupported type\n");
                break;
        }
    }
}

/*
 * Function: fetch_number()
 * ----------------------
 * Description:
 *      Outputs prompt, reads input using fgets(),
 *      converts it to the selected type, and validates 
 *      the input.
 */
void fetch_number(void *input, const char *prompt, double min, double max, Fetch_Type type)
{
    char buffer[BUFFER];

    do
    {
        char *endptr;
        errno = 0;

        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin))
        {
            double value = strtod(buffer, &endptr);

            if (is_empty(buffer)) 
            {
                print_error("Input cannot be empty of a new line character\n");
                continue;
            }
            else if (validate(endptr, strtod(buffer, &endptr), min, max))
            {
                print_error("Input is invalid: non-number or invalid range\n");
                print_warning("Input must be in range [ %.1lf ] => [ %.1lf ]\n", min, max);
                continue;
            }

            switch (type)
            {
                case TYPE_LD:
                    *(long *)input = (long)strtol(buffer, &endptr, 10);
                    break;
                case TYPE_LLD:
                    *(long long *)input = (long long)strtoll(buffer, &endptr, 10);
                    break;
                case TYPE_O:
                    *(unsigned long *)input = (unsigned long)strtoul(buffer, &endptr, 8);
                    break;
                case TYPE_X:
                    *(unsigned long *)input = (unsigned long)strtoul(buffer, &endptr, 16);
                    break;
                case TYPE_F:
                    *(float *)input = (float)strtof(buffer, &endptr);
                    break;
                case TYPE_LF:
                    *(double *)input = (double)strtod(buffer, &endptr);
                    break;
                default:
                    fputs("[!] Unsupported type\n", stderr);
                    continue;
                }
            break;
        }
        else
            print_error("Error reading input\n");

    } while (true);
}

/*
 * Function: fetch_string()
 * ----------------------
 * Description:
 *      Fetches a string value from the user.
 */
void fetch_string(char *input, const char *prompt) 
{
    char buffer[BUFFER];

    do
    {
        printf("%s", prompt);

        if (fgets(buffer, BUFFER, stdin) == NULL)
        {
            print_error("Error reading input\n");
            print_warning("Buffer cannot be empty\n");
            continue;
        }

        strncpy(input, buffer, BUFFER - 1);
        input[BUFFER - 1] = '\0';
        input[strcspn(input, "\n")] = '\0';
        break;

    } while (true);
}

/* fetch_utils.c */