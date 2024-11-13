/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : print_utils.c
 * Author       : Heisnx (c)
 * Date Created : 04/11/2024
 * Last Modified: 12/11/2024
 * 
 * Description:
 *      This source file contains functions oriented
 *      at printing elements out stylistically.
 *
 * Warnings:
 *      - No notable warnings as of v1.0.2
 */

/* [ Headers ] */
#include <custom_utils.h>
#include <print_utils.h>

/* [ Colours ] */

const Color RED = { "\x1b[31m", NULL };
const Color GREEN = { "\x1b[32m", NULL };
const Color YELLOW = { "\x1b[33m", NULL };
const Color BLUE = { "\x1b[34m", NULL };
const Color MAGENTA = { "\x1b[35m", NULL };
const Color CYAN = { "\x1b[36m", NULL };

/* [ Arrays ]*/

size_t type_sizes[] = {
    [TYPE_INT] = sizeof(int),
    [TYPE_LONG] = sizeof(long),
    [TYPE_LONG_LONG] = sizeof(long long),
    [TYPE_FLOAT] = sizeof(float),
    [TYPE_DOUBLE] = sizeof(double),
};

/* [ Functions ] */

/*
 * print_divider()
 * ----------------------
 * Description:
 *      Prints out a divider made of custom size out of
 *      your preffered characters.
 * 
 * Notes:
 *      - Used to be falsely called print_separator() lol.
 *      - Updated in v1.1.0
 */
void print_divider(size_t len, Char_Type divider)
{
    char ch = char_determ(divider);

    for (size_t i = 0; i < len; ++i)
        printf("%c", ch);

    printf("\n");
}

/*
 * print_array()
 * ----------------------
 * Description:
 *      Prints the elements of an array in a formatted list.
 */
void print_array(void *arr, int len, const char *msg, Fetch_Type type)
{
    printf(BOLD "%s " RESET, msg);
    printf("{ ");
    printf(GREEN.fg_color);

    for (int i = 0; i < len; ++i)
    {
        print_type_determ(arr, type, i);

        if (i < len - 1)
            printf(", ");
    }

    printf(RESET " }\n");
}

/*
 * print_matrix()
 * ----------------------
 * Description:
 *      Prints the elements of a matrix in a formatted manner,
 *      by calling print_array() for each row.
 */
void print_matrix(void **matrix, int rows, int cols, const char *msg, Fetch_Type type)
{
    printf(BOLD "%s " RESET, msg);
    printf("{\n");

    // Iterate through each row
    for (int i = 0; i < rows; ++i) 
    {
        print_array(matrix[i], cols, "Row", type);
    }

    printf("}\n");
}

/*
 * Function: print_progress_bar()
 * ----------------------
 * Description:
 *      Prints a progress bar.
 */
void print_progress_bar(int progress, int total, int width, Char_Type fill_complete, Char_Type fill_remaining)
{
    char fill, empty;

    switch(fill_complete)
    {
        case DASH:          fill = '-'; break;
        case EQUALS:        fill = '='; break;
        case ASTERISK:      fill = '*'; break;
        case TILDE:         fill = '~'; break;
        case HASH:          fill = '#'; break;
        case UNDERSCORE:    fill = '_'; break;
        default:            fill = '='; break;
    }

    switch(fill_remaining)
    {
        case DASH:          empty = '-'; break;
        case EQUALS:        empty = '='; break;
        case ASTERISK:      empty = '*'; break;
        case TILDE:         empty = '~'; break;
        case HASH:          empty = '#'; break;
        case UNDERSCORE:    empty = '_'; break;
    }

    if (total <= 0 || width <= 0) 
    {
        print_log("[!]", RED, "Total and width must be greater than 0\n");
        return;
    }
    else if (progress > total)
    {
        print_log("[!]", RED, "Progress made cannot be larger than total: [ %d ] > [ %d ]\n", progress, total);
        return;
    }

    float ratio = (float)progress / total;
    int pos = (int)width * ratio;

    printf("[");
    for (int i = 0; i < width; ++i) 
    {
        if (i < pos) 
            printf("%c", fill);
        else 
            printf("%c", empty);
    }
    
    printf("] %.2f%%\n", ratio * 100);
    fflush(stdout);
}

/*
 * Function: print_log()
 * ----------------------
 * Description:
 *      Prints out an log message with whatever amount of arguments.
 */
void print_log(const char *prefix, Color color, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    if (color.fg_color)
    {
        fprintf(stderr, "%s%s%s%s" RESET " ", color.fg_color, color.bg_color ? color.bg_color : "", BOLD, prefix);
        fprintf(stderr, "%s%s", color.fg_color, color.bg_color ? color.bg_color : "");
    }

    vfprintf(stderr, format, args);
    fprintf(stderr, RESET);
    va_end(args);
}

/* print_utils.c */