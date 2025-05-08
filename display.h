#ifndef DISPLAY_H
#define DISPLAY_H

#include "shop.h"

/*
 * Name: print_options
 * Description: Print options to the user
 */
void print_otions();

/**
 * Name: print_selection_error
 * Description: Print error message for selecting a bad option
*/
void print_selection_error();

/*
 * THIS IS A SUGGESTED FUNCTION. IT IS IMPLEMENTED FOR YOU IN
 *		`display.cpp`
 * Name: get_option
 * Description: Prompt the user for their numbered option selection
 * Returns (int): The number associated with the option selected by the user
 */
int get_option();

/*
 * THIS IS A SUGGESTED FUNCTION. IT IS PARTIALLY IMPLEMENTED FOR YOU IN
 *		`display.cpp`.
 * Name: execute_option
 * Description: Execute the option selected by the user
 * parameters:
 *		s (shop&): A reference to the shop object
 *		option (int): The user's selected option to execute. Must be
 *			between 1 and 7 (inclusive).
 */
void execute_option(shop& s, menu& m, int option);

#endif // DISPLAY_H