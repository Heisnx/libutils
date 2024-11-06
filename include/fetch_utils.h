/*
 * [ libcustomutils ]
 * ----------------------
 * File Name    : fetch_utils.h
 * Author       : Heisnx (c)
 * Date Created : 05/10/2024
 * Last Modified: 05/11/2024
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
 * Return: -
 */
void fetch_number_array(void *arr, int len, const char *prompt, Fetch_Type type, double min, double max, bool disp_cnt);

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

#endif // FECTH_UTILS_H

/* fetch_utils.h */
