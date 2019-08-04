#include "../include/remove_tests_mode.h"
#include <fstream>

std::vector < std::string> tests_file_to_vector(std::string tester_name)
{
    std::ifstream test_file( tester_name + ".TM" + "/" + tester_name + ".tests" );

    std::string curr_line;
    std::vector <std::string> tests_vector;

    while( test_file.good() )
    {
        getline(test_file, curr_line);
        tests_vector.push_back(curr_line);
    }

    return tests_vector;
}

std::vector <std::vector <std::string> > vectorize_tests(std::vector <std::string> file_vector)
{
    std::vector <std::vector <std::string>> tests_vector;

    int line_num = 0;
    int num_lines = file_vector.size();

    while(line_num < num_lines)
    {
        std::vector <std::string> curr_test_vector;
        
        //every test inp/output ends with ~x~
        while(file_vector[line_num] != "~x~")
        {
            curr_test_vector.push_back( file_vector[line_num++] );
        }

        tests_vector.push_back(curr_test_vector);
    }

    return tests_vector;
}

void remove_tests_mode(std::string tester_name)
{
    std::vector <std::vector <std::string>> tests_vector = vectorize_tests( tests_file_to_vector( tester_name ) );
    
    return ;
}