#ifndef _RECORD_H
#define _RECORD_H

#include <iostream>

class Record
{
    private:

    std::string input;
    std::string output;

    public:
    
    Record(std::string new_input, std::string new_output) : input(new_input), output(new_output){};
    void write_record(std::string filename);
};

#endif