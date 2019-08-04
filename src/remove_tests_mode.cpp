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

    while(line_num < num_lines - 1)
    {
        std::vector <std::string> curr_test_vector;

        //every test inp/output ends with ~x~
        while(file_vector[line_num] != "~x~")
        {
          //  std::cerr << "ConcernFrogeasd\n";
            curr_test_vector.push_back( file_vector[line_num++] );
        }
        curr_test_vector.push_back( file_vector[line_num++] );
        tests_vector.push_back(curr_test_vector);
    }

    return tests_vector;
}

void print_tests(std::vector <std::vector<std::string> > tests_vector )
{
    for(int n = 0; n < tests_vector.size(); n++)
    {
        std::cout << "\nTest #" << n << "\n\n";
        std::cout << "Input: " << std::endl;

        int curr_test_line = 0;

        while (tests_vector[n][curr_test_line] != "~z~")
        {
            std::cout << tests_vector[n][curr_test_line++] << std::endl;
        }

        std::cout << "\nOutput: " << std::endl;

        //push past ~z~
        curr_test_line++;

        while(tests_vector[n][curr_test_line] != "~x~")
        {
            std::cout<< tests_vector[n][curr_test_line++] << std::endl;
        }
        
    }
}

void write_test_changes(std::string tester_name, std::vector <std::vector<std::string> > tests_vector)
{

}

void remove_tests_mode(std::string tester_name)
{
    std::vector <std::vector <std::string>> tests_vector = vectorize_tests( tests_file_to_vector( tester_name ) );
    
    print_tests(tests_vector);

    std::string user_input;

    std::cout << "Select a test to remove, or nothing to cancel: ";
    getline(std::cin, user_input);

    int users_choice = stoi(user_input);

    tests_vector.erase( tests_vector.begin() + users_choice);

    write_test_changes(tester_name, tests_vector);
    
    return ;
}

