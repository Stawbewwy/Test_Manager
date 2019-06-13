#include "../include/generate_program.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits>

/** 
    @tester_name: the name of desired tester.
    @destination: fstream to have another file written to. Written by reference.
    @source:    fstream to be copied.

 */
void create_input_buffer(std::string tester_name, std::ofstream &destination, std::ifstream &source)
{
    std::string temp;

    //load the file buffer with the screen inputs
    while( source.good() )
    {
        
        getline(source, temp);
        
        destination << temp << std::endl;
    }

    //load the file buffer with the tests
    std::ifstream tester_fstream( (tester_name + ".tests") );

    while( tester_fstream.good() )
    {
        getline(tester_fstream, temp);
        destination << temp << std::endl;
    }


    return;
}

//@tester_name: the name of desired tester.
//@program_name: the name of the program being tested.
//the actual execution of a tester.
void exec_test(std::string tester_name, std::string program_name)
{
    int input_fd = open((tester_name + ".buffer").c_str(), O_RDONLY);
    int output_fd = open( (tester_name + ".output").c_str(), O_RDWR | O_CREAT, S_IRWXU );

    //change stdin to the correct input
    dup2(input_fd,STDIN_FILENO);
    close(input_fd);

    //change stdout to a new file
    dup2(output_fd, STDOUT_FILENO);
    close(output_fd);

    char* argv[2];

    argv[0] = (char*) program_name.c_str();
    //argv[0] = (char*)"./addition_calculator.x";
    argv[1] = NULL;

    if ( execvp(argv[0], argv) < 0)
    {
        std::cerr << program_name.c_str();
        std::cerr << "Error executing desired program!" <<std::endl;
        exit(-1);
    }
}
void print_pass()
{
    std::cout << "\033[1;32m\t\tPass!\033[0m\n";
}

void print_failed()
{
    std::cout << "\033[1;31m\t\tFailed! \033[0m ";
}
/** Function that will run the test and display results.*/
/** @tester_name; the name of the tester program. */
void run_test(std::string tester_name, std::string program_name, int num_lines_down,std::string input, std::string ans)
{
    //We will be doing the fork + exec combo to test each input.
    //int test_fd = open((tester_name + ".buffer").c_str(), O_RDWR);

    int curr_test = fork();
        
    //Child is the test. Rather than piping the results, we'll just leave a note in a file.
    if(curr_test == 0)
    {
        
        exec_test(tester_name, program_name);
    }

    else
    {
        waitpid(curr_test, NULL, 0);
        std::ifstream output_file( (tester_name) + ".output" );
        std::string result;

        //Push file offset to the output of the test
        for(int n = 0; n < num_lines_down; n++)
        {
            getline(output_file, result);
        }

        //extract the output
        getline(output_file, result);

        std::cout << "\n\nInput: " << input << "\t Expected Answer: " << ans << std::endl;
        std::cout << "\nOutput: " << result;
        
        if(result == ans)
        {
             print_pass();
        }

        else
        {
            print_failed();
            //std::cout << result << std::endl;
        }
        
    }


}

void get_inp_out (std::string line, std::string &input, std::string &output)
{
    //everything until first tab is the input.
    input = line.substr(0, line.find_first_of('\t') );

    output = line.substr( line.find_first_of('\t') +1 );
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
    getline(meta_file,program_name);
    //pull num lines down out of meta file.
    meta_file >> num_lines_down;


    std::ifstream input_file( ( tester_name + ".input") );
    std::ifstream tests_file( (tester_name + ".tests"));

    //while ( tests_file >> input >> ans  )
    while ( tests_file.good() )
    {
        std::string temp;

        getline(tests_file, temp);

        //last input is going to be a blank line. This is a false line.
        if(temp != "")
        {
            get_inp_out(temp, input, ans);


            //Need to reset offset to beginning of file each iteration.        
            input_file.seekg(0);

            //If for some reason this file already exists, we need to remove it to reset the contents.
            remove( (tester_name + ".buffer").c_str() );
            remove( (tester_name + ".output").c_str() );

            std::ofstream tester_buffer((tester_name + ".buffer"));
            
            //Copy the inputs to get to the input to test
            create_input_buffer(tester_name, tester_buffer, input_file);

            run_test(tester_name, program_name, num_lines_down, input, ans);    
        }

    }
}

void generate_program()
{
    std::string tester_name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the name of the tester you want to generate: ";
    getline(std::cin, tester_name);

    create_source_code(tester_name);

    return ;
}