#include <stdlib.h>
#include <iostream>
#include "../include/modify_existing_tester.h"
#include <experimental/filesystem>
#include "../include/modify_tester.h"
#include "../include/helper_functions.h"

void modify_existing_tester()
{
    while(1)
    {
        std::cout << "\n\n==== Modify Existing Tester ====" << std::endl;
        
        std::cout << "\nCurrent Directory: " << std::experimental::filesystem::current_path() << std::endl << std::endl;

        std::cout << "1 -- Select Tester" << std::endl;
        std::cout << "2 -- Change Working Directory" << std::endl;
        std::cout << "3 -- Return to Main Menu" << std::endl;

        std::cout << std::endl <<"Please enter an option: ";

        int user_choice;
        std::cin >> user_choice;

        switch (user_choice)
        {
            case 1:
            {
                std::string tester = select_existing_tester();

                if( tester != "")
                {
                    modify_tester();
                }

                break;
            }

            case 2:
            {
                set_working_dir();
                break;
            }

            case 3:
            {
                //returns to main menu
                return;
            }

            default:
            {
                break;
            }
        }

        
    }
}
