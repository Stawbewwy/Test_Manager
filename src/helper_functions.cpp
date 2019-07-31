#include "../include/helper_functions.h"
#include <experimental/filesystem>
#include <iostream>
#include <limits>

void get_existing_testers()
{
    std::cout << std::endl;
    for (const auto & entry : std::experimental::filesystem::directory_iterator( std::experimental::filesystem::current_path() ) ) {
        
        //entry.length() -4 gets us to where we would expect the .TM extension part of a tester name, and the 3 characters checks that part out

        std::string entry_str = entry.path();
        
        if( entry_str.length() >= 3 && ( entry_str.substr( entry_str.length() - 3, 3 ) == ".TM") ){
            std::cout << entry.path() << std::endl;
        }
        
    }

    std::cout << std::endl;
}

std::string select_existing_tester()
{
    bool valid = false;
    
    std::string temp;
    
    get_existing_testers();

    while(!valid){
        std::cout << "Select a tester (include the .TM extension, only the tester name, not entire path) or enter 0 to cancel: ";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(std::cin, temp);

        if (temp == ""){
            return "";
        }

        for (const auto & entry : std::experimental::filesystem::directory_iterator( std::experimental::filesystem::current_path() ) ) {        
            if (entry == temp){
                return temp;
            }
        }
    
    }
}

void set_working_dir()
{
    std::string temp;

    std::cout << "Enter a new directory to change to: ";

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, temp);

    std::experimental::filesystem::current_path(temp);

    return;
}