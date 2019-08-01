#include "../include/add_or_remove_menu.h"
#include "../include/add_tests_mode.h"
#include "../include/remove_tests_mode.h"

void add_or_remove_menu(std::string tester_name)
{

    std::cout << "\n\n==== Add or Remove Tests ====" << std::endl;
        
   // std::cout << "\nCurrent Directory: " << std::experimental::filesystem::current_path() << std::endl << std::endl;
    std::cout << "\nSelected Tester: " << tester_name << std::endl << std::endl;
    std::cout << "1 -- Add Tests" << std::endl;
    std::cout << "2 -- Remove Tests" << std::endl;
    std::cout << "3 -- Return to Previous Menu" << std::endl;

    std::cout << std::endl <<"Please enter an option: ";
    
    int user_choice;
    std::cin >> user_choice;

    switch(user_choice)
    {
        case 1:
        {
            add_tests_mode();
            break;
        }

        case 2:
        {
            remove_tests_mode();
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