// #define TEST_OUTPUT
// #define TEST_GAMEBOARD_1
// #define TEST_GETCH
// #define TEST_GAMEBOARD_2
// #define TEST_VVINT

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../include/characters.hpp"
#include "../include/formats.hpp"
#include "../include/GameBoard.hpp"
#include "../include/getkey.hpp"

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

    // Color 16
    for (int code = 0; code < 16; code++)
        std::cout << color_16_foreground("Hello world!", code) << " " << color_16_background("Hello world!", code) << std::endl;
    std::cout << std::endl;

    // Color 256
    for (int code = 0; code < 256; code++)
        std::cout << color_256_foreground("Hello world!", code) << " " << color_256_background("Hello world!", code) << std::endl;
    std::cout << std::endl;

    // Color RGB
    for (int r_code = 0; r_code < 256; r_code += 16)
        for (int g_code = 0; g_code < 256; g_code += 16)
            for (int b_code = 0; b_code < 256; b_code += 16)
                std::cout << color_rgb_foreground("Hello world!", r_code, g_code, b_code) << " "
                          << color_rgb_background("Hello world!", r_code, g_code, b_code) << std::endl;
    std::cout << std::endl;

#endif

#ifdef TEST_GAMEBOARD_1
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

#ifdef TEST_GETCH
    while (true)
    {
        int t = getkey();
        std::cout << "Your input unicode: " << t << std::endl;
    }
#endif

#ifdef TEST_GAMEBOARD_2

    GameBoard gb_0(4);
    GameBoard gb_1(4, 35, {{0, 2, 0, 0}, {0, 0, 4, 0}, {2, 2, 32, 8}, {4, 4, 8, 16}});
    GameBoard gb_2(4, 8818, {{0, 2, 0, 0}, {0, 0, 4, 0}, {2, 2, 32, 8}, {4, 4, 2048, 16384}});
    GameBoard gb_3(4, 124514, {{4, 8, 16, 32}, {512, 256, 128, 64}, {1024, 2048, 4096, 8192}, {131072, 65536, 32768, 16384}});

    gb_0.show();
    gb_1.show();
    gb_2.show();
    gb_3.show();

#endif

#ifdef TEST_VVINT
    VVINT vvint_1 = {{1, 2}, {3, 4}};
    VVINT vvint_2 = vvint_1;
    vvint_2[0][0] = 0;
    for (auto i : vvint_1)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    for (auto i : vvint_2)
    {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
#endif

    return 0;
}