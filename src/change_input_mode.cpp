#include "../include/change_input_mode.h"
#include "../include/helper_functions.h"
#include <fstream>

void change_input_mode(std::string tester_name)
{
    std::cout << "Please specify the input sequence to get to where in the program YOU WANT to test (One input per line, enter nothing to end): ";

    std::string input_sequence = get_tester_input();

    std::ofstream input_file;
    input_file.open(tester_name + ".TM" + "/" + tester_name + ".input", std::ofstream::out | std::ofstream::trunc);

    input_file << input_sequence;

    return;

}