#include "../include/add_tests_mode.h"
#include "../include/helper_functions.h"
#include "../include/Record.h"

void add_tests_mode(std::string tester_name)
{
    std::string new_input;
    std::string new_output;
    std::string temp = "x";

    std::cout << "Please enter the next input to test: ";
    new_input = get_tester_input();

    new_input += "\n";
    
    std::cout << "Please enter the correct output for that input(enter nothing to stop): \n";

    //build output sequence
    while(temp != "")
    {
        getline(std::cin, temp);
        new_output += ("\n" + temp);
    }

    Record new_record(new_input, new_output);

    new_record.write_record(tester_name);

    return;
}