// #define TEST_GETKEY
#define TEST_INPUT

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/characters.hpp"
#include "../include/formats.hpp"
#include "../include/GameBoard.hpp"
#include "../include/utils.hpp"

int main()
{
    std::srand(std::time(nullptr));

#ifdef TEST_GETKEY
    while (true)
    {
        int key = getkey();
        std::cout << key << std::endl;
    }
#endif

#ifdef TEST_INPUT
    while (true)
    {
        std::cout << input("Your input: ") << std::endl;
    }
#endif

    return 0;
}