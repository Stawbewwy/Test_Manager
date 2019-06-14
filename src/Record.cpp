#include "../include/Record.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

void Record::write_record(std::string filename)
{
    std::ofstream file;

    file.open( (filename + ".tests"), std::ios::out | std::ios::app );
    file << input << "\t" << output << std::endl <<"~x~"; 

    file.close();

    std::cout << "\n\nOK, record successfully added!\n\n";
}