#include "../include/generate_program.h"
#include <iostream>
#include <fstream>

void create_source_code(std::string tester_name)
{
    std::string source;

    // source = "#include <iostream>\n
    //           \n
    //           int main()\n
    //           {
    //               while
    //           }
    //           "
}

void generate_program()
{
    std::string tester_name;
    std::cout << "Enter the name of the tester you want to generate: ";
    getline(std::cin, tester_name);

    create_source_code(tester_name);

    return ;
}