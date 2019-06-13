#include "../include/generate_program.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

/** 
    @destination: fstream to have another file written to. Written by reference.
    @source:    fstream to be copied.

 */
void copy_data_file(std::ofstream &destination, std::ifstream &source)
{
    std::string temp;

    while(source.good())
    {
        getline(source, temp);

        destination << temp << std::endl;
    }

    return;
}

void create_source_code(std::string tester_name)
{
    std::string source;
    
    char curr_inp;

    int num_lines_down;
    std::string input, ans;
    
    /** READ THE META DETA FILE*/

    std::ifstream input_file( ( tester_name + ".input") );
    std::ifstream meta_file((tester_name + ".meta"));
    std::ifstream tests_file( (tester_name + ".tests"));
    
    
    // Pull the file name of the desired tester.
    getline(meta_file,source);

    //Pull the number of lines down out of meta file.
    meta_file >> num_lines_down;

    int stdin_backup = dup(STDIN_FILENO);

    while ( input_file >> input >> ans  )
    {

        //Need to reset offset to beginning of file each iteration.        
        input_file.seekg(0);

        //If for some reason this file already exists, we need to remove it to reset the contents.
        remove( (tester_name + ".buffer").c_str() );
        std::ofstream tester_fstream((tester_name + ".buffer"));
        
        //Copy the inputs to get to the input to test
        copy_data_file(tester_fstream, input_file);

        //We will be doing the fork + exec combo to test each input.
        int test_fd = open((tester_name + ".buffer").c_str(), O_RDWR);

        int curr_test = fork();
        
        //Child is the test
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