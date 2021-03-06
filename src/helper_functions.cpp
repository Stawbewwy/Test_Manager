#include "../include/helper_functions.h"
#include <experimental/filesystem>
#include <iostream>
#include <limits>

std::string get_tester_input()
{
    std::string temp;
    std::string input;
    
    temp = "x";
    while(temp != "")
    {
        getline(std::cin, temp);
        input += temp + "\n";
    }

    //-2 to get index position, and remove the final new line.
    return input.substr(0, input.length()-2);
}

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

std::string extract_tester_name(std::string entry){
    //we assume already that the .TM exists

    int curr_pos = entry.length()-4;
    std::string name;

    while(entry[curr_pos] != '/')
    {
        name.insert(0, 1 , entry[curr_pos]);
        curr_pos--;
    }

    return name;
}

std::string select_existing_tester()
{
    bool valid = false;
    
    std::string user_entry;
    
    get_existing_testers();

    std::cerr << "Select a tester (Do not include the .TM extension): \n" << std::endl;
    getline(std::cin, user_entry);

    for (const auto & entry : std::experimental::filesystem::directory_iterator( std::experimental::filesystem::current_path() ) ) {
        
        std::string entry_str = entry.path();
        
        //only consider entires that have a possibility of being valid
        if( entry_str.length() >= 3 && ( entry_str.substr( entry_str.length() - 3, 3 ) == ".TM") ){
            if ( user_entry == extract_tester_name(entry_str) ){
                return user_entry;
            }
        }   
        
    }

    std::cout << "Sorry, couldn't find that tester.\n";
    
    return "";
}

void set_working_dir()
{
    std::string temp;

    std::cout << "Enter a new directory to change to: ";

    getline(std::cin, temp);

    if(temp == "")
    {
        temp = ".";
    }

    std::experimental::filesystem::current_path(temp);

    return;
}