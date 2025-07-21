#include <iostream>

#include "../include/clearConsole.hpp"

void clear_console()
{
    std::cout << "\033[2J\033[H" << std::flush;
}