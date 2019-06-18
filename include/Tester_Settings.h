//#include <stdlib.h>
//#include <stdio.h>
#ifndef _TESTER_SETTINGS_H
#define _TESTER_SETTINGS_H
#include <string>

/**
*   Class that stores all settings of a program when entered. Used primarily to easily handle the data and encapsulate it .meta and .input files.
*
*/
class Tester_Settings
{
    private:
        std::string program_name;
        std::string output_directory;
        std::string output_name;
        std::string input_sequence;
        int num_lines_down;
    
    public:
        Tester_Settings(std::string new_program, std::string new_output_directory, std::string new_output_name, std::string new_input_seq, int new_num_lines) 
                        : program_name(new_program), output_directory(new_output_directory) ,
                          output_name(new_output_name), input_sequence(new_input_seq), num_lines_down(new_num_lines){};

        void set_program_name(std::string new_program){ program_name = new_program; };
        void set_output_directory(std::string new_output_directory){ output_directory = new_output_directory; };
        void set_output_name(std::string new_output_name){ output_name = new_output_name; };
        void set_input_sequence(std::string new_input_seq) {input_sequence = new_input_seq; };
        void set_num_lines_down(int new_num_lines) {num_lines_down = new_num_lines; };

        std::string get_program_name(){ return program_name; };
        std::string get_output_directory(){ return output_directory; };
        std::string get_output_name(){ return output_name; };
        std::string get_input_sequence(){ return input_sequence; };
        int get_num_lines_down(){ return num_lines_down; };

        /**
        * Function that writes both the settings to std::cout and to a .input and .meta file.
        *
        */
        void print_settings();
};
#endif