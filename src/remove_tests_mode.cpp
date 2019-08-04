#include "../include/remove_tests_mode.h"
#include <fstream>
std::vector < string> tests_file_to_vector(std::string tester_name)
{
    ifstream test_file( tester_name + ".TM" + "/" + tester_name + ".tests" );

    std::string curr_line;
    std::vector tests_vector;

    while( test_file.good() )
    {
        getline(test_file, curr_line);
        tests_vector.push(curr_line);
    }

    return tests_vector;
}

void get_tests(std::vector <string> tests_vector)
{

    if(tests_vector.size() != 0)
    {
        while
    }
}

std::vector <string> vectorize_tests(std::vector <string> file_vector)
{
    
}

void remove_tests_mode(std::string tester_name)
{
    std::vector <string> tests_vector = vectorize_tests( tests_file_to_vector( tester_name ) );
    
    return ;
}