#ifndef _EDIT_PROGRAM_H
#define _HELPER_FUNCTIONS_H

/**
*   Function that lists every found tester in the current working directory
*/
void get_existing_testers();

/**
*   Function that lists all testers in CWD
*   Returns the empty string if user enters nothing or a string of the program name they chose
*/

std::string select_existing_tester();

/**
*   Function that sets the working directory to what the user specifies.
*   Upon entering an invalid directory, the directory will remain to what it was before the change.
*/
bool::set_working_dir();

#endif