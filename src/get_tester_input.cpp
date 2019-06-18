
#include <iostream>
#include "../include/get_tester_input.h"

std::string get_tester_input()
{
  std::string temp = "x";
  
  std::string input;

  while(temp != "")
  {
    getline(std::cin, temp);
    input += temp + "\n";
  }

  //-2 to get index position, and remove the final new line.
  return input.substr(0, input.length()-2);
}