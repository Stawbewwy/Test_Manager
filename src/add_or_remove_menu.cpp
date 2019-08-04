#include "../include/add_or_remove_menu.h"
#include "../include/add_tests_mode.h"
#include "../include/remove_tests_mode.h"

void add_or_remove_menu(std::string tester_name)
{
    while(1)
    {
        std::cout << "\n\n==== Add or Remove Tests ====" << std::endl;
            
    // std::cout << "\nCurrent Directory: " << std::experimental::filesystem::current_path() << std::endl << std::endl;
        std::cout << "\nSelected Tester: " << tester_name << std::endl << std::endl;
        std::cout << "1 -- Add Tests" << std::endl;
        std::cout << "2 -- Remove Tests" << std::endl;
        std::cout << "3 -- Return to Previous Menu" << std::endl;

        std::cout << std::endl <<"Please enter an option: ";

        std::string user_input;
        getline(std::cin, user_input);
        int user_choice = stoi(user_input);

        std::cout << std::endl;

        switch(user_choice)
        {
            case 1:
            {
                add_tests_mode(tester_name);
                break;
            }

            case 2:
            {
                remove_tests_mode(tester_name);
                break;
            }
            
            case 3:
            {
                return;
            }

            default:
            {
                break;
            }
        }
    }
}