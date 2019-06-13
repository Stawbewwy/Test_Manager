#include "../include/generate_program.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <unistd.h>

/** 
    @destination: fstream to have another file written to. Written by reference.
    @source:    fstream to be copied.

 */
void create_input_buffer(std::ofstream &destination, std::ifstream &source, std::string tester_name)
{
    std::string temp;

    //load the file buffer with the screen inputs
    while(source.good())
    {
        getline(source, temp);

        destination << temp << std::endl;
    }

    //load the file buffer with the tests
    std::ifstream tester_fstream( (tester_name + ".tests") );

    while(tester_fstream >> temp)
    {
        destination << temp << endl;
    }


    return;
}

/** This function actually runs the test for a desired input to check */
/** @tester_name; the name of the tester program. */
void run_test(std::string tester_name, std::string program_name)
{
    //We will be doing the fork + exec combo to test each input.
    //int test_fd = open((tester_name + ".buffer").c_str(), O_RDWR);

    int curr_test = fork();
        
    //Child is the test. Rather than piping the results, we'll just leave a note in a file.
    if(curr_test == 0)
    {
        int input_fd = open((tester_name + ".buffer").c_str(), O_RDONLY);
        int output_fd = open( (tester_name + ".output").c_str(), O_RDONLY );

        //change stdin to the correct input
        dup2(input_fd,STDIN_FILENO);
        close(input_fd);

        //change stdout to a new file
        dup2(output_fd, STDOUT_FILENO);
        close(output_fd);

        char* argv[2];

        argv[0] = (char*) program_name.c_str();
        argv[1] = NULL;
        
        if ( execvp(argv[0], argv) < 0)
        {
            std::cout << "Error executing desired program!" <<std::endl;
            exit(-1);
        }
    }
}

/** @tester_name; the name of the tester program. */
void create_source_code(std::string tester_name)
{
    
    
    char curr_inp;

    int num_lines_down;
    std::string input, ans;
    
    /** READ THE META DETA FILE*/
    std::ifstream meta_file((tester_name + ".meta"));    
    std::string program_name;

    // Pull the file name of the desired tester.
    getline(meta_file,source);
    //pull num lines down out of meta file.
    meta_file >> num_lines_down;


    std::ifstream input_file( ( tester_name + ".input") );
    std::ifstream tests_file( (tester_name + ".tests"));

    while ( input_file >> input >> ans  )
    {

        //Need to reset offset to beginning of file each iteration.        
        input_file.seekg(0);

        //If for some reason this file already exists, we need to remove it to reset the contents.
        remove( (tester_name + ".buffer").c_str() );
        std::ofstream tester_buffer((tester_name + ".buffer"));
        
        //Copy the inputs to get to the input to test
        create_input_buffer(file_name, tester_buffer, input_file);

        run_test(tester_name);
    }
}

void generate_program()
{
    std::string tester_name;
    std::cout << "Enter the name of the tester you want to generate: ";
    getline(std::cin, tester_name);

    create_source_code(tester_name);

    return ;
}