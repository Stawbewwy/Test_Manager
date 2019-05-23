#include "../include/add_new_program.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <limits>

void add_new_program ()
{
    std::string program_name;
    std::string input_sequence;
    int num_lines_down;
    std::string chars_to_skip;

    std::cout << "Please enter the name of the program you wish to test: ";
    getline(std::cin, program_name);

    std::cout << "Please specify the input sequence to get to where in the program YOU WANT to test: ";
    getline(std::cin, input_sequence);
    std::cout << "Please specify exactly how many lines down on the output of your program the result will lie: ";
    
    std::cin >> num_lines_down;

      std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Please specify any characters that are encounted before the result, ON THE SAME LINE of the result (each followed by a comma, e.g, +, ,!): ";
    getline(std::cin, chars_to_skip);

    std::cout << "Attempting to find target program..." << std::endl;
    
}