#include "../include/Tester_Settings.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>

void Tester_Settings::print_settings()
{
    std::cout << "\n\n==== WRITTING SETTINGS OBJECT ====\n";
    std::cout << "Program Name: " << program_name << std::endl;
    std::cout << "Output Directory: " << output_directory << std::endl;
    std::cout << "Output Name: " << output_name << std::endl;
    std::cout << "Input Sequence: " <<input_sequence << std::endl;
    std::cout << "Num Lines Down: " <<num_lines_down << std::endl;


    //Note that we append the / ourselves. The user must not input it.
    std::string record_location = output_directory + "/" + output_name + ".TM" + "/" + output_name;

     std::experimental::filesystem::create_directory( output_directory + "/" + output_name + ".TM" );
     std::experimental::filesystem::permissions(output_directory + "/" + output_name + ".TM", std::experimental::filesystem::perms::owner_all);


    std::string input_file = record_location + ".input";
    std::string meta_file = record_location + ".meta";

    //Going to write two new info files.
    std::ofstream inputfs( input_file, std::ios::out | std::ios::app );
    std::ofstream metafs ( meta_file, std::ios::out | std::ios::app );
    
    inputfs << input_sequence;
    inputfs.close();

    metafs << program_name << std::endl
           << num_lines_down;
    metafs.close();

    std::cout << "OK. Program added to records!\n\n"; 
}