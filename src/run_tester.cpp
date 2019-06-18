#include "../include/run_tester.h"
#include <iostream>
#include <fstream>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits>
#include <algorithm>
#include "Tester_Info.h"

/**
    @input: string to be tokenized to proper std input. Breaks every , into a blank.
*/
std::string parse_input(std::ifstream &tests_file)
{
    std::string temp = "x";

    std::string test;


    while(temp != "~z~" && temp != "")
    {
        getline(tests_file, temp);

        test += temp + "\n";
    }

    if(temp == "")
    {
        return test;
    }

    return test.erase( ( (int)test.length() ) - 1 - 4, 5);

}

std::string parse_output(std::ifstream &tests_file, int &num_ans_lines)
{
    std::string ans, temp;

    while(temp != "~x~")
    {
        getline(tests_file, temp);
        num_ans_lines++;
        ans += (temp + "\n");
    }

    //erase the appended "\n~x~";    
    ans.erase(ans.length() - 1 - 4,5);
    num_ans_lines--;

    return ans;
}

void remove_intermediates(std::string file_name)
{
    
    remove( (file_name + ".buffer").c_str() );
    remove((file_name + ".output").c_str() );

    return ;
}

int file_get_num_lines(std::string file_name)
{
    int counter = 0;
    std::string temp;

    std::ifstream file(file_name);

    while (file.good())
    {
        getline(file, temp);
        counter++;
    }

    return counter - 1;
}

void create_input_buffer(std::string tester_name, std::ofstream &destination, std::ifstream &source, std::string test_input)
{
    std::string temp;

    //lines -1 to get rid of a null line
    for(int n = 0 ; n < file_get_num_lines(tester_name + "/" + tester_name + ".input") - 1 ; n++ )
    {
        getline(source, temp);
        destination << temp << std::endl;
    }

    //load the file buffer with the tests
    destination << test_input << std::endl;

    return;
}

void print_pass()
{
    std::cout << "\033[1;32m\t\tPassed!\033[0m\n";
}

void print_failed()
{
    std::cout << "\033[1;31m\t\tFailed! \033[0m \n";
}

//@tester_name: the name of desired tester.
//@program_name: the name of the program being tested.
//the actual execution of a tester.
void exec_test(std::string tester_name, std::string program_name)
{
    int input_fd = open( ( tester_name+ "/" + tester_name + ".buffer").c_str(), O_RDONLY);
    int output_fd = open( (tester_name+ "/" + tester_name + ".output").c_str(), O_RDWR | O_CREAT, S_IRWXU );

    //change stdin to the correct input
    dup2(input_fd,STDIN_FILENO);
    close(input_fd);

    //change stdout and stderr to a new file
    dup2(output_fd, STDOUT_FILENO);
    dup2(output_fd, STDERR_FILENO);
    close(output_fd);

    char* argv[2];

    argv[0] = (char*) program_name.c_str();
    argv[1] = NULL;

    if ( execvp(argv[0], argv) < 0)
    {
        std::cerr << program_name.c_str();
        std::cerr << "Error executing desired program!" <<std::endl;
        exit(-1);
    }
}

/** Function that will run the test and display results.*/
/** @tester_name; the name of the tester program. */
void run_test(Tester_Info tester_settings)
{
    //We will be doing the fork + exec combo to test each input.

    int curr_test = fork();
        
    //Child is the test. Rather than piping the results, we'll just leave a note in a file.
    if(curr_test == 0)
    {
        
        exec_test( tester_settings.get_tester_name(), tester_settings.get_program_name() );
    }
    else
    {
        waitpid(curr_test, NULL, 0);
        std::ifstream output_file( tester_settings.get_tester_name() + "/" + tester_settings.get_tester_name() + ".output" );
        std::string result;
        
        //string buffer
        std::string temp;

        //Push file offset to the output of the test
        for(int n = 0; n < tester_settings.get_num_lines_down(); n++)
        {
            getline(output_file, temp);
        }

        //extract the output
        for(int n = 0; n < tester_settings.get_num_ans_lines(); n++)
        {   
            getline(output_file, temp);
            result += temp + "\n";
        }

        //remove the "\n" @ end
        result.erase( result.length()-1, 1);
        
        std::cout << "\n==== Test #" << tester_settings.get_test_num() << " ====";

        if(result == tester_settings.get_ans())
        {
             print_pass();
        }

        else
        {
            print_failed();
        }

        std::cout << "\nInput: \n" << tester_settings.get_input() << "\n\nExpected Answer: \n" << tester_settings.get_ans() << std::endl;
        std::cout << "\nOutput: \n" << result << std::endl;
    }


}

/** @tester_name; the name of the tester program. */
void run_tests(std::string tester_name)
{
    int num_lines_down;
    int num_ans_lines;
    std::string test_input = "x", ans;
    
    /** READ THE META DETA FILE*/
    std::ifstream meta_file(tester_name + "/" + tester_name + ".meta");    
    std::string program_name;

    // Pull the file name of the desired tester.
    getline(meta_file,program_name);
    //pull num lines down out of meta file.
    meta_file >> num_lines_down;


    std::ifstream input_file( tester_name + "/" + tester_name + ".input" );
    std::ifstream tests_file( tester_name + "/" + tester_name + ".tests");

    int test_num = 0;

    while ( tests_file.good() )
    {
        std::string temp;

       // ans = "";
        num_ans_lines = 0;

        //pull out the input we are going to be testing.
        test_input = parse_input(tests_file);


        //last read will pull a blank line.
        if( tests_file.good() ){

            test_num++;

            //get correct output to the current test, update 
            ans = parse_output(tests_file, num_ans_lines);


            //Need to reset offset to beginning of file each iteration.        
            input_file.seekg(0);

            //If file already exists, we need to remove it to reset the contents.

            remove_intermediates(tester_name + "/" + tester_name);

            std::ofstream tester_buffer(tester_name + "/" + tester_name + ".buffer");
            
            //Copy the inputs to get to the input to test
            create_input_buffer(tester_name, tester_buffer, input_file, test_input);
            
            Tester_Info tester_settings(num_lines_down, num_ans_lines, test_num, program_name ,tester_name, test_input, ans);
            
            run_test(tester_settings);    

            }
    }

    //remove these intermediate files automatically.
    remove_intermediates(tester_name + "/" + tester_name);

    return;
}


void run_tester()
{
    std::string tester_name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the name of the tester you want to generate: ";
    getline(std::cin, tester_name);

    run_tests(tester_name);

    return ;
}