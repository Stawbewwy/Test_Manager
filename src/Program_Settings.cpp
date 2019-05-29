#include "../include/Program_Settings.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

static std::string parse_input(std::string input)
{
    std::string temp = input;


    for(int n = 0; n < input.length(); n++)
    {
        if(input[n] == ','){
            temp[n] = '\n';
        }
    }

    return temp;
}

void Program_Settings::print_settings()
{
    std::cout << "\n\n==== WRITTING SETTINGS OBJECT ====\n";
    std::cout << "Program Name: " << program_name << std::endl;
    std::cout << "Output Directory: " << output_directory << std::endl;
    std::cout << "Output Name: " << output_name << std::endl;
    std::cout << "Input Sequence: " <<input_sequence << std::endl;
    std::cout << "Num Lines Down: " <<num_lines_down << std::endl;

    //std::ofstream records;

    //Note that we append the / ourselves. The user must not input it.
    std::string record_location = output_directory + "/" + output_name;
    std::string input_file = record_location + ".input";
    std::string meta_file = record_location + ".meta";

    // records.open( record_location, std::ios::out | std::ios::app );
    // records << "#$#" << std::endl
    //         << program_name << std::endl 
    //         << input_sequence << std::endl
    //         << num_lines_down << std::endl;
    // records.close();

    std::ofstream inputfs( input_file, std::ios::out | std::ios::app );
    std::ofstream metafs ( meta_file, std::ios::out | std::ios::app );
    
    std:: cout << parse_input(input_sequence) << "xd" << std::endl;
    inputfs << parse_input(input_sequence);
    inputfs.close();

    metafs << program_name << std::endl
           << num_lines_down;
    metafs.close();

    std::cout << "OK. Program added to records!\n\n"; 
}