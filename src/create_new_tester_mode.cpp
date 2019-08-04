#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <limits>
#include "../include/create_new_tester_mode.h"
#include "../include/Tester_Settings.h"



Tester_Settings get_program_info()
{
    std::string program_name;
    std::string output_directory;
    std::string input_sequence;
    std::string output_name;
    //buffer to get num_lines_down from user
    std::string user_input;

    int num_lines_down;

    std::cout << "Please enter the name of the program you wish to test: ";
    getline(std::cin, program_name);

    std::cout << "Please enter the name of the output directory: ";
    getline(std::cin, output_directory);

    std::cout << "Please enter a desired output name: ";
    getline(std::cin, output_name);

    std::cout << "Please specify the input sequence to get to where in the program YOU WANT to test (One input per line, enter nothing to end): ";

    input_sequence = get_tester_input();

    std::cout << "Please specify exactly how many lines down on the output of your program the result will lie: ";
    getline(std::cin, user_input);
    num_lines_down = stoi(user_input);

    std::cout << std::endl;
  
    
    std::cout << "Attempting to find target program..." << std::endl;

    

    return ( Tester_Settings(program_name, output_directory, output_name ,input_sequence, num_lines_down) );
}

void add_new_tester()
{

  Tester_Settings program_info = get_program_info();

  //write the settings into a file
  program_info.print_settings();

}