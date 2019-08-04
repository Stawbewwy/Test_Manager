#include "../include/change_meta_mode.h"
#include <iostream>
#include <fstream>

void change_meta_mode(std::string tester_name)
{
    std::string program_name;
    std::string user_input;

    std::cout << "Please enter the name of the program you wish to test (include what is needed to execute it): ";
    getline(std::cin, program_name);

    std::cout << "Please specify exactly how many lines down on the output of your program the result will lie: ";
    getline(std::cin, user_input);
    int num_lines_down = stoi(user_input);

    std::ofstream meta_file;
    meta_file.open(tester_name + ".TM" + "/" + tester_name + ".meta", std::ofstream::out | std::ofstream::trunc);

    meta_file << program_name << std::endl;
    meta_file << num_lines_down;

    return;
}