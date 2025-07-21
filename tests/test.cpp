// #define TEST_OUTPUT
#define TEST_GAMEBOARD

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/characters.hpp"
#include "../include/formats.hpp"
#include "../include/GameBoard.hpp"

int main()
{

    std::srand(std::time(nullptr));

#ifdef TEST_OUTPUT
    // Characters
    std::cout << FULLBLOCK << std::endl;
    std::cout << DARKSHADE << std::endl;
    std::cout << MEDIUMSHADE << std::endl;
    std::cout << LIGHTSHADE << std::endl;
    for (const std::string &block : LOWERBLOCKS)
    {
        std::cout << block << " ";
    }
    std::cout << std::endl;
    std::cout << UPPERHALFBLOCK << std::endl;
    std::cout << LOWERHALFBLOCK << std::endl;
    std::cout << LEFTHALFBLOCK << std::endl;
    std::cout << RIGHTHALFBLOCK << std::endl;
    for (const std::string &bar : VERTICALBARS)
    {
        std::cout << bar << " ";
    }
    std::cout << std::endl
              << std::endl;

    // Font weight
    std::cout << "Hello world!" << std::endl;
    std::cout << bold("Hello world!") << std::endl;
    std::cout << std::endl;

    // Italic
    std::cout << "Hello world!" << std::endl;
    std::cout << italic("Hello world!") << std::endl;
    std::cout << std::endl;

    // Underline
    std::cout << "Hello world!" << std::endl;
    std::cout << underline("Hello world!") << std::endl;
    std::cout << std::endl;

    // Color - foreground
    std::cout << color("30", "Hello world!") << std::endl;
    std::cout << color("31", "Hello world!") << std::endl;
    std::cout << color("32", "Hello world!") << std::endl;
    std::cout << color("33", "Hello world!") << std::endl;
    std::cout << color("34", "Hello world!") << std::endl;
    std::cout << color("35", "Hello world!") << std::endl;
    std::cout << color("36", "Hello world!") << std::endl;
    std::cout << color("37", "Hello world!") << std::endl;
    std::cout << std::endl;

    // Color - background
    std::cout << color("40", "Hello world!") << std::endl;
    std::cout << color("41", "Hello world!") << std::endl;
    std::cout << color("42", "Hello world!") << std::endl;
    std::cout << color("43", "Hello world!") << std::endl;
    std::cout << color("44", "Hello world!") << std::endl;
    std::cout << color("45", "Hello world!") << std::endl;
    std::cout << color("46", "Hello world!") << std::endl;
    std::cout << color("47", "Hello world!") << std::endl;
    std::cout << std::endl;
#endif

#ifdef TEST_GAMEBOARD
    GameBoard gb(4);
    while (true)
    {
        gb.generate_new();
        gb.show();
        std::cout << std::endl;
        std::cout << "1 - Up; 2 - Right; 3 - Down; 4 - Left. Choose your option." << std::endl;
        int opt = 0;
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            gb.move_up();
            break;
        case 2:
            gb.move_right();
            break;
        case 3:
            gb.move_down();
            break;
        case 4:
            gb.move_left();
            break;
        default:
            break;
        }
        std::cout << std::endl;
    }
#endif

    return 0;
}