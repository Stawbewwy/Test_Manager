#include "../include/delete_tester_mode.h"
#include "../include/helper_functions.h"
#include <experimental/filesystem>

void delete_tester_mode()
{
    std::string tester = select_existing_tester();

    if(tester != "")
    {
        bool deleted = std::experimental::filesystem::remove_all(tester + ".TM");

        if(deleted)
        {
            std::cout << "Tester deleted!\n\n";
        }
    }

    return;
}