#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <experimental/filesystem>
#include "../include/main_menu.h"
#include "../include/create_new_tester_mode.h"
#include "../include/modify_tester_menu.h"
#include "../include/run_tester_mode.h"
#include "../include/delete_tester_mode.h"


void main_menu()
{
    while(1)
    {
        std::cout << "\n\n==== Main Menu ====" << std::endl;
        
        std::cout << "\nCurrent Directory: " << std::experimental::filesystem::current_path() << std::endl << std::endl;

        std::cout << "1 -- Create New Tester" << std::endl;
        std::cout << "2 -- Modify Existing Tester" << std::endl;
        std::cout << "3 -- Delete Existing Tester" << std::endl;
        std::cout << "4 -- Run Tester" << std::endl;
        std::cout << "5 -- Exit" << std::endl;

        std::cout << std::endl <<"Please enter an option: ";

        
        std::string user_input;

        getline(std::cin, user_input);
        int user_choice = stoi(user_input);

        std::cout << std::endl;

        switch (user_choice)
        {
            case 1:
            {
                add_new_tester();

                break;
            }

            case 2:
            {
                modify_existing_tester();
                break;
            }

            case 3:
            {
                delete_tester_mode();
                break;
            }

             case 4:
            {

                 run_tester();

                break;
            }

            case 5:
            {
                std::cout <<"Thank you for using Test Manager! Have a good one!" << std::endl;
                exit(0);
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
