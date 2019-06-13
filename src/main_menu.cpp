#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "../include/main_menu.h"
#include "../include/add_new_tester.h"
#include "../include/update_existing_program.h"
#include "../include/generate_program.h"
#include <experimental/filesystem>

void main_menu()
{
    while(1)
    {
        std::cout << "\n\n==== Main Menu ====" << std::endl;
        
        std::cout << "\nCurrent Directory: " << std::experimental::filesystem::current_path() << std::endl << std::endl;

        std::cout << "1 -- Create New Tester" << std::endl;
        std::cout << "2 -- Update Existing Tester" << std::endl;
        std::cout << "3 -- Delete Existing Tester" << std::endl;
        std::cout << "4 -- Generate New Tester Program" << std::endl;
        std::cout << "5 -- Exit" << std::endl;

        std::cout << std::endl <<"Please enter an option: ";

        int user_choice;
        std::cin >> user_choice;

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
                update_existing_program();
                break;
            }

            case 3:
            {
                break;
            }

             case 4:
            {

                 generate_program();

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
