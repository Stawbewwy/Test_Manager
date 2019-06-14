#ifndef _TESTER_INFO_H
#define _TESTER_INFO_H

#include <iostream>

Class Tester_Info
{
    private: 
    int num_lines_down, num_ans_lines;
    std::string input, ans;

    public:
    Tester_Info(int inp_num_lines_down, int inp_num_ans_lines, std::string inp_input, std::string inp_ans) 
            :   num_lines_down(inp_num_lines_down), num_ans_lines(num_ans_lines), input(inp_input), ans(inp_ans){};

} 