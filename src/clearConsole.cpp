#include <iostream>

#include "../include/clearConsole.hpp"

void clear_console()
{
    std::cout << "\033c" << std::flush;
}