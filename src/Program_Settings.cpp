#include "../include/Program_Settings.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

void Program_Settings::print_settings()
{
    std::cout << "\n\n==== WRITTING SETTINGS OBJECT ====\n";
    std::cout << "Program Name: " << program_name << std::endl;
    std::cout << "Output Directory: " << output_directory << std::endl;
    std::cout << "Output Name: " << output_name << std::endl;
    std::cout << "Input Sequence: " <<input_sequence << std::endl;
    std::cout << "Num Lines Down: " <<num_lines_down << std::endl;

    std::ofstream records;

    //Note that we append the / ourselves. The user must not input it.
    std::string record_location = output_directory + "/" + output_name;
    records.open( record_location, std::ios::out | std::ios::app );
    records << "#$#" << std::endl
            << program_name << std::endl 
            << input_sequence << std::endl
            << num_lines_down << std::endl;
    records.close();

    std::cout << "OK. Program added to records!\n\n"; 
}