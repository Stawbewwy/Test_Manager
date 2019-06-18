#ifndef _GENERATE_PROGRAM_H
#define _GENERATE_PROGRAM_H
#include "../include/Tester_Info.h"

/**
*   Function to get test inputs of current test out of .tests file
*
*   @tests_file -   File Stream that takes the .tests file, and will extract every input line until the answers
*/
std::string parse_input(std::ifstream &tests_file);

/**
*   Function to get correct test outputs for current test out of .tests file
*   
*   @tests_file -   File stream that takes the .tests file, and will extract every output line until the beginning of next input or end of file.
*   @num_ans_lines -    Record how many answer lines we read, store in @num_ans_lines
*/

std::string parse_output(std::ifstream &tests_file, int &num_ans_lines);

/**
*   Function to remove the intermediate .buffer and .output files left from running tests
*
*   @file_name -    The name of the tester we are running.
*/
void remove_intermediates(std::string file_name);

/**
*   Function to get the number of lines in a given file
*
*   @file_name -    The name of the file we are checking the # of lines of.
*/

int file_get_num_lines(std::string file_name);

/**
*   Function that creates a buffer to be used as stdin when executing the program we are testing. Concatenates the .input file with the inputs
*   in the .test file.
*
*   @tester_name -  The name of the tester we are testing.
*   @destination -  The file we are writing to (this will be the buffer)
*   @source -   The .input file
*   @test_input -   The input from the .tests file extracted into a string
*/

void create_input_buffer(std::string tester_name, std::ofstream &destination, std::ifstream &source, std::string test_input);

void print_pass();

void print_failed();

/**
*   Function that actually executes the program we are testing and records the output.
*
*   @tester_name -   The name of the tester we are testing.
*   @program_name -  The name of the program we are testing.
*/

void exec_test(std::string tester_name, std::string program_name);

/**
*   Function that will carry out a test and check if the current test suceeds or fails.
*
*   @tester_settings -  All of the tester information extracted in the run_tests() function.
*/

void run_test(Tester_Info tester_settings);
/**
*   Function that loops through .tests file and continues to run tests until there are none left for the selected tester.
*
*   @tester_name -  The name of the tester we are testing.
*/

void run_tests(std::string tester_name);

/**
*   Function that gets the name of the tester user wants to test, and then calls run_tests() to begin the testing process.
*
*/

void run_tester();



#endif