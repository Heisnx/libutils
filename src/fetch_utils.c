/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : fetch_utils.c
 * Author       : Heisnx (c)
 * Date Created : 04/11/2024
 * Last Modified: 12/11/2024
 * 
 * Description:
 *      This source file contains functions oriented
 *      at receiving user input.
 */

/* [ Headers ] */
#include <custom_utils.h>
#include <fetch_utils.h>

/*
 * fetch_array()
 * ----------------------
 * Description:
 *      Reads array elements with fetch().
 *      Has the option to display remaining elements.
 */
void fetch_array(void *arr, int len, const char *prompt, Fetch_Type type, double min, double max, bool disp_cnt)
{
    char buffer[BUFFER];

    for (int i = 0; i < len; ++i) 
    {
        if (disp_cnt)
            snprintf(buffer, sizeof(buffer), "%s [%d]/[%d]: ", prompt, i + 1, len);
        else
            snprintf(buffer, sizeof(buffer), "%s", prompt);

        void *element = (char *)arr + i * type_sizes[type];
        fetch_array_element(element, buffer, min, max, type);
    }
}

/*
 * Function: fetch_number()
 * ----------------------
 * Description:
 *      Outputs prompt, reads input using fgets(),
 *      converts it to the selected type, and validates 
 *      the input.
 * 
 * Notes:
 *      - Uses print_error() and print_warning() from print_utils.h
 *      - Uses CONVERT_INPUT() from custom_utils.h
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
                print_log("[ERROR]", RED, "Input cannot be empty of a new line character\n");
                continue;
            }
            else if (validate(endptr, strtod(buffer, &endptr), min, max))
            {
                print_log("[ERROR]", RED, "Input is invalid: non-number or invalid range\n");
                print_log("[WARNING]", YELLOW, "Input must be in range [ %.1lf ] => [ %.1lf ]\n", min, max);
                continue;
            }

            convert_input(input, value, type);
            break;
        }
        else
            print_log("[ERROR]", RED, "Error reading input\n");

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
            print_log("[ERROR]", RED, "Error reading input\n");
            print_log("[WARNING]", YELLOW, "Buffer cannot be empty\n");
            continue;
        }

        strncpy(input, buffer, BUFFER - 1);
        input[BUFFER - 1] = '\0';
        input[strcspn(input, "\n")] = '\0';
        break;

    } while (true);
}

/*
 * fetch_matrix()
 * --------------
 * Description:
 *      Dynamically allocates and fills a matrix of given number of rows, where each row is an array.
 *      Calls fetch_number_array() for each row, allowing customization of prompt, type, min, and max.
 */
int fetch_matrix(void ***matrix, int rows, int cols, const char *prompt, Fetch_Type type, double min, double max, bool disp_cnt)
{
    bool is_interactive = isatty(fileno(stdin));

    *matrix = malloc(rows * sizeof(void *));
    if (*matrix == NULL) 
    {
        print_log("[ERROR]", RED, "Memory allocation failed for matrix rows\n");
        return -1;
    }

    for (int i = 0; i < rows; ++i) 
    {
        size_t row_size = type_sizes[type] * cols;
        (*matrix)[i] = malloc(row_size);

        if ((*matrix)[i] == NULL) 
        {
            print_log("[ERROR]", RED, "Memory allocation failed for a matrix row\n");

            for (int j = 0; j < i; ++j)
                free((*matrix)[j]);

            free(*matrix);
            return -1;
        }

        char row_prompt[BUFFER];

        if (is_interactive)
            snprintf(row_prompt, sizeof(row_prompt), "%s (Row %d)", prompt, i + 1);
        else 
            row_prompt[0] = '\0';

        fetch_array((*matrix)[i], cols, row_prompt, type, min, max, disp_cnt);
    }

    return 0;
}



/* fetch_utils.c */