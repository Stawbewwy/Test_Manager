#include "../include/update_existing_program.h"
#include <iostream>

void update_existing_program()
{
    std::string curr_dir = ".";
    int option;
    while(1)
    {
        std::cout << "==== Update Existing Program ====" << std::endl;
        std::cout << "Current Directory: " << curr_dir << std::endl
                  << "1 -- Select File to Edit" << std::endl
                  << "2 -- List all Files in Current Directory" << std::endl
                  << "3 -- Change Current Directory" << std::endl
                  << "4 -- Return to Main Menu" << std::endl
                  << "Please enter an option: ";
        std::cin >> option;

        switch(option)
        {
            case 1:
            {
                break;
            }

            case 2:
            {
                break;
            }

            case 3:
            {
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