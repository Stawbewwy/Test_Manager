#include "../include/generate_program.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

void create_source_code(std::string tester_name)
{
    std::string source;
    
    char curr_inp;

    int num_lines_down;
    char input, ans;
    
    /** READ THE META DETA FILE*/

    std::ifstream meta_file((tester_name + ".meta"));
    std::ifstream input_file( ( tester_name + ".input"));
    
    
    // Pull the file name of the desired tester.
    getline(meta_file,source);

    //Pull the number of lines down out of meta file.
    meta_file >> num_lines_down;

    int stdin_backup = dup(STDIN_FILENO);

    while ( input_file >> input >> ans  )
    {
        remove( (tester_name + ".test").c_str() );
        
        int test_fd = open((tester_name + ".test").c_str(), O_RDWR);

        int curr_test = fork();

        //Child
        if(curr_test == 0)
        {
            //change stdin to the correct input
            //change stdout to a new file
            //execvp
        }

        //otherwise, we're parent and we process data.
        //wait for child, read the file, compare the results
        
    }

    /** ASSIGN INPUT TO BE THE*/ 



    //Pull


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