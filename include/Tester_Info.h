#ifndef _TESTER_INFO_H
#define _TESTER_INFO_H

#include <iostream>

class Tester_Info
{
    public: 
    int num_lines_down, num_ans_lines;
    std::string program_name, tester_name, input, ans;

    public:
    Tester_Info(int inp_num_lines_down, int inp_num_ans_lines, std::string inp_program_name , std::string inp_tester_name ,
                std::string inp_input, std::string inp_ans) 
            :   num_lines_down(inp_num_lines_down), num_ans_lines(inp_num_ans_lines), program_name(inp_program_name), tester_name(inp_tester_name) 
                ,input(inp_input), ans(inp_ans){};
            
    int get_num_lines_down(){ return num_lines_down; };
    int get_num_ans_lines(){ return num_ans_lines; };
    std::string get_program_name(){ return program_name; };
    std::string get_tester_name(){ return tester_name; };
    std::string get_input(){ return input; };
    std::string get_ans(){ return ans; };
    

};

#endif