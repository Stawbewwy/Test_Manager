// Credit to Shreevardhan @Stackoverflow, https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c 

#include "../include/update_existing_program.h"
#include "../include/Record.h"
#include <iostream>
#include <limits>
#include <experimental/filesystem>

std::string get_valid_file()
{
    std::string temp;

    std::cout << "Enter the desired file name: ";
    getline(std::cin, temp);

    return temp;
}

void edit_record_file(std::string file)
{
    std::string new_input;
    std::string new_output;

    std::cout << "Please enter the next input to test: ";
    getline(std::cin, new_input);

    std::cout << "Please enter the correct output for that input: ";
    getline(std::cin, new_output);

    Record new_record(new_input, new_output);

    new_record.write_record(file);
}
void change_directory()
{
    std::cout << "Please enter the new desired directory: ";
    
    std::string temp;
    getline(std::cin, temp);
    
    std::experimental::filesystem::current_path(temp);
     return;
}

void list_curr_dir()
{
    std::cout << std::endl;
    for (const auto & entry : std::experimental::filesystem::directory_iterator( std::experimental::filesystem::current_path() ) )
        std::cout << entry.path() << std::endl;
    
    std::cout << std::endl;
    return;
}

void update_existing_program()
{
    int option;

    while(1)
    {   
        std::cout << "\n==== Update Existing Program ====" << std::endl;
        std::cout << "\nCurrent Directory: " << std::experimental::filesystem::current_path() << std::endl << std::endl

                  << "1 -- Select Tester to Edit" << std::endl
                  << "2 -- List all Files in Current Directory" << std::endl
                  << "3 -- Change Current Directory" << std::endl
                  << "4 -- Return to Main Menu" << std::endl
                  << "\nPlease enter an option: ";
        
        std::cin >> option;
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(option)
        {
            case 1:
            {       
                edit_record_file( get_valid_file() );
                break;
            }

            case 2:
            {
                list_curr_dir();
                break;
            }

            case 3:
            {
                change_directory();
                break;
            }
           
            case 4:
            {
                return;
            }

            default:
            {
                std::cout << "\nError! Please enter a valid choice.\n";
                break;
            }
        }

    }

}