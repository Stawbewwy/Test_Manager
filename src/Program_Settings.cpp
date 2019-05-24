#include "../include/Program_Settings.h"
#include <stdlib.h>
#include <iostream>

void Program_Settings::print_settings()
{
    std::cout << "\n\n==== PRINTING SETTINGS OBJECT ====\n\n";
    std::cout << "Program Name: " << program_name << std::endl;
    std::cout << "Input Sequence: " <<input_sequence << std::endl;
    std::cout << "Num Lines Down: " <<num_lines_down << std::endl;
}