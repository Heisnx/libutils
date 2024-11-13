/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : fetch_utils.h
 * Author       : Heisnx (c)
 * Date Created : 04/11/2024
 * Last Modified: 12/11/2024
 * 
 * Description  :
 *      This file contains all of the declarations for
 *      fetch_utils.c specifically.
 */

#ifndef FETCH_UTILS_H
#define FETCH_UTILS_H

/* [ Headers ] */
#include <custom_utils.h>
#include <print_utils.h>

/* 
 * [WARNING]: Your IDE might not find the file, so you might have to 
 * include that within your settings.json (if on Visual Studio Code)
 * or alter the include path to match the location of custom_utils.h
 */

/* 
 * [WARNING]: This header already include print_utils.h,
 * so there is no need to re-do that when needing to use
 * print_utils.h functions.
 */

/*
 * [INFO]: The full description of each function will be present
 * within the header only - the function definitions in the source files
 * will only have a shortened description for code clarity.
 */

/* [ Functions ] */

/*
 * Function: fetch_array()
 * ----------------------
 * Description:
 *      Reads arrays based off of fetch_number().
 *
 * Arguments:
 *      arr         : Void pointer to an integer or double array.
 *      len         : Number of elements in the array.
 *      prompt      : Prompt message to display for each element.
 *      type        : The data type that is expected.
 *      min         : Minimal argument accepted.
 *      max         : Maximal argument accepted.
 *      disp_cnt    : The option to display counter.
 * 
 * Returns: -
 */
void fetch_array(void *arr, int len, const char *prompt, Fetch_Type type, double min, double max, bool disp_cnt);

/*
 * Function: fetch_number()
 * ----------------------
 * Description:
 *      Outputs prompt, reads input using fgets(),
 *      converts it to selected type, and validates 
 *      the input.
 * 
 * Arguments:
 *      - input : The variable where we store the input.
 *      - prompt: The prompt displayed to the user.
 *      - min   : The minimal accepted value [NUMBER ONLY].
 *      - max   : The maximal accepcted value [NUMBER ONLY].
 *      - type  : The type of the final value.
 * 
 * Return: -
 */
void fetch_number(void *input, const char *prompt, double min, double max, Fetch_Type type);

/*
 * Function: fetch_string()
 * ----------------------
 * Description:
 *      Fetches a string value from the user.
 * 
 * Arguments:
 *      - input     : Where to store the input.
 *      - prompt    : Message sent out to user.
 * 
 * Return: - 
 */
void fetch_string(char *input, const char *prompt);

/*
 * fetch_matrix()
 * --------------
 * Description:
 *      Dynamically allocates and fills a matrix of given number of rows, where each row is an array.
 *      Calls fetch_number_array() for each row, allowing customization of prompt, type, min, and max.
 *
 * Arguments:
 *      - matrix      : Pointer to the matrix (array of arrays) to be allocated and filled.
 *      - rows        : Number of rows in the matrix.
 *      - cols        : Number of columns in each row.
 *      - prompt      : Prompt for user input.
 *      - type        : Data type of the elements (uses Fetch_Type enum from fetch_number_array()).
 *      - min         : Minimum valid value for input elements.
 *      - max         : Maximum valid value for input elements.
 *      - disp_cnt    : Whether to display count of remaining elements.
 *
 * Returns:
 *      0 on success, -1 on allocation error.
 * 
 * Warning:
 *      Uses memory allocation.
 */
int fetch_matrix(void ***matrix, int rows, int cols, const char *prompt, Fetch_Type type, double min, double max, bool disp_cnt);

/* [ Inline Functions ] */

/*
 * Function: convert_input()
 * ----------------------
 * Description:
 *      Converts to proper type.
 */
static inline void convert_input(void * input, double value, Fetch_Type type)
{
    switch(type)
    {
        case TYPE_INT:          (*(int*)input = (int)value); break;
        case TYPE_LONG:         (*(long*)input = (long)value); break;
        case TYPE_LONG_LONG:    (*(long long*)input = (long long)value); break;
        case TYPE_FLOAT:        (*(float*)input = (float)value); break;
        case TYPE_DOUBLE:       (*(double*)input = (double)value); break;
        default:                input = 0; break;
    }
}

/*
 * fetch_array_element()
 * ----------------------
 * Description:
 *      A helper function to convert the array element based on type.
 */
static inline void fetch_array_element(void *element, const char *prompt, double min, double max, Fetch_Type type)
{
    switch(type)
    {
        case TYPE_INT:          fetch_number((int*)element, prompt, min, max, type);                break;
        case TYPE_LONG:         fetch_number((long*)element, prompt, min, max, type);               break;
        case TYPE_LONG_LONG:    fetch_number((long long*)element, prompt, min, max, type);          break;
        case TYPE_FLOAT:        fetch_number((float*)element, prompt, min, max, type);              break;
        case TYPE_DOUBLE:       fetch_number((double*)element, prompt, min, max, type);             break;
        default:                print_log("[ERROR]", RED, "Unsupported type for array element\n");  break;
    }
}

#endif // FECTH_UTILS_H

/* fetch_utils.h */
