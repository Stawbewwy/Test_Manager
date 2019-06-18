#ifndef _GENERATE_PROGRAM_H
#define _GENERATE_PROGRAM_H
#include "../include/Tester_Info.h"

std::string parse_input(std::ifstream &tests_file);

std::string parse_output(std::ifstream &tests_file, int &num_ans_lines);

void remove_intermediates(std::string file_name);

int file_get_num_lines(std::string file_name);

void create_input_buffer(std::string tester_name, std::ofstream &destination, std::ifstream &source, std::string test_input);

void print_pass();

void print_failed();

void exec_test(std::string tester_name, std::string program_name);

void run_test(Tester_Info tester_settings);

void run_tests(std::string tester_name);





void run_tester();



#endif