#include "test_utilities.h"

#include <iostream>

void print_pass()
{
    std::cout << "\033[1;32m\t\tPassed!\033[0m\n";
}

void print_failed()
{
    std::cout << "\033[1;31m\t\tFailed! \033[0m \n";
}