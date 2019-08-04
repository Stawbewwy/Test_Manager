#ifndef _REMOVE_TESTS_MODE_H
#define _REMOVE_TESTS_MODE_H

#include <vector>
#include <iostream>

/**
*   Function that opens the .tests file for a tester and dumps it into a vector, line by line (each line is an element of vector)
*   @tester_name: the name of the tester being converted
*/
std::vector <std::string> tests_file_to_vector(std::string tester_name);

/**
*   Function that will tkae a .tests file that is in a vector form, and create a new vector that contains all tests.
*   @file_vector: vector that contains the .tests file (in vector form)
*/
std::vector <std::vector <std::string>> vectorize_tests(std::vector <std::string> file_vector);

/**
*   Function that runs through a vector with tests and prints out what each test is.
*/
void print_tests(std::vector <std::vector<std::string> > tests_vector );

/**
*   Function that takes all modifications to tests (removed ones) and updates the .tests file to reflect the changes
*   @tester_name: the name of the tester being altered
*   @tests_vector: the vector that contains the remaining tests
*/
void write_tests(std::string tester_name, std::vector <std::vector<std::string> > tests_vector);

/**
*   Function that will allow user to remove tests from a tester
*   @tester_name: the name of the tester being altered
*/
void remove_tests_mode(std::string tester_name);

#endif