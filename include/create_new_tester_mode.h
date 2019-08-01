#ifndef _ADD_NEW_PROGRAM_H
#define _ADD_NEW_PROGRAM_H
#include "Tester_Settings.h"
#include <stdlib.h>

/**
* Function that builds a string to store the input needed to get to the location we are testing in the users desired program.
*/
std::string get_tester_input();

/**
*   Function that requests the information of a new tester from user, and creates a Tester_Settings objects containing all of it.
*/
Tester_Settings get_program_info();

/**
*   Function that adds a new tester
*/
void add_new_tester();


#endif