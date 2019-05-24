#include "../include/add_new_program.h"
#include "../include/Program_Settings.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <limits>


Program_Settings get_program_info()
{
    std::string program_name;
    std::string output_directory;
    std::string input_sequence;
    std::string output_name;
    int num_lines_down;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Please enter the name of the program you wish to test: ";
    getline(std::cin, program_name);

    std::cout << "Please enter the name of the output directory: ";
    getline(std::cin, output_directory);

    std::cout << "Please enter a desired output name: ";
    getline(std::cin, output_name);

    std::cout << "Please specify the input sequence to get to where in the program YOU WANT to test: ";
    getline(std::cin, input_sequence);
    std::cout << "Please specify exactly how many lines down on the output of your program the result will lie: ";
    
    std::cin >> num_lines_down;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Attempting to find target program..." << std::endl;

    

    return ( Program_Settings(program_name, output_directory, output_name ,input_sequence, num_lines_down) );
}

void add_new_program()
{

  Program_Settings program_info = get_program_info();

  program_info.print_settings();

      

  /**From here, we need to write this into our records*/   
}