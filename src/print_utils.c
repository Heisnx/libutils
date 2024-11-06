/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : print_utils.c
 * Author       : Heisnx (c)
 * Date Created : 29/10/2024
 * Last Modified: 04/11/2024
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
    char ch;

    switch(divider)
    {
        case DASH:          ch = '-'; break;
        case EQUALS:        ch = '='; break;
        case ASTERISK:      ch = '*'; break;
        case TILDE:         ch = '~'; break;
        case HASH:          ch = '#'; break;
        case UNDERSCORE:    ch = '_'; break;
    }

    for (size_t i = 0; i < len; ++i)
        printf("%c", ch);

    printf("\n");
}

/*
 * print_number_array()
 * ----------------------
 * Description:
 *      Prints the elements of an array in a formatted list.
 */
void print_number_array(void *arr, int len, const char *msg, Fetch_Type type)
{
    printf(BOLD "%s\n" RESET, msg);
    printf("\t{ ");

    for (int i = 0; i < len; ++i)
    {
        switch (type)
        {
            case TYPE_LD:
                printf(GREEN "%ld", *((long int *)arr + i));
                break;
            case TYPE_LLD:
                printf(GREEN "%lld", *((long long int *)arr + i));
                break;
            case TYPE_F:
                printf(GREEN "%.2f", *((float *)arr + i));
                break;
            case TYPE_LF:
                printf(GREEN "%.2lf", *((double *)arr + i));
                break;
            default:
                print_warning("Unsupported type\n");
                return;
        }

        if (i < len - 1)
            printf(", ");
    }

    printf( RESET " }\n");
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
        print_error("[!] Total and width must be greater than 0\n");
        return;
    }
    else if (progress > total)
    {
        print_error("[!] Progress made cannot be larger than total: [ %d ] > [ %d ]\n", progress, total);
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
 * Function: print_warning()
 * ----------------------
 * Description:
 *      Prints out a warning message with whatever amount of arguments.
 */
void print_warning(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    fprintf(stderr, BOLD YELLOW "[?] ");
    vfprintf(stderr, format, args);
    fprintf(stderr, RESET);
    va_end(args);
}

/*
 * Function: print_error()
 * ----------------------
 * Description:
 *      Prints out an error message with whatever amount of arguments.
 */
void print_error(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    fprintf(stderr, BOLD RED "[!] ");
    vfprintf(stderr, format, args);
    fprintf(stderr, RESET);
    va_end(args);
}

/*
 * Function: print_debug()
 * ----------------------
 * Description:
 *      Prints out a debug message with whatever amount of arguments.
 */
void print_debug(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    fprintf(stderr, BOLD BLUE "[*] ");
    vfprintf(stderr, format, args);
    fprintf(stderr, RESET);
    va_end(args);
}


/* print_utils.c */