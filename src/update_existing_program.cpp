// Credit to Shreevardhan @Stackoverflow, https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c 

#include "../include/update_existing_program.h"
#include <iostream>
#include <limits>
#include <experimental/filesystem>

std::string curr_dir;

void change_directory()
{
    std::cout << "Please enter the new desired directory: ";
     getline(std::cin, curr_dir);

     return;
}

void list_curr_dir()
{
    std::string path = "./records";
    for (const auto & entry : std::experimental::filesystem::directory_iterator(path))
        std::cout << entry.path() << std::endl;

    return;
}

void update_existing_program()
{
    curr_dir = ".";
    int option;
    while(1)
    {
        std::cout << "\n==== Update Existing Program ====" << std::endl;
        std::cout << "Current Directory: " << curr_dir << std::endl
                  << "1 -- Select File to Edit" << std::endl
                  << "2 -- List all Files in Current Directory" << std::endl
                  << "3 -- Change Current Directory" << std::endl
                  << "4 -- Return to Main Menu" << std::endl
                  << "\nPlease enter an option: ";
        
        std::cin >> option;
        
        //Flush cin buffer after previous operation.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(option)
        {
            case 1:
            {
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
                break;
            }

            default:
            {
                std::cout << "Error! Please enter a valid choice.";
                break;
            }
        }

    }

}