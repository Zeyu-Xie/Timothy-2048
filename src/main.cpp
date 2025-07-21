#include "../include/characters.hpp"
#include "../include/clearConsole.hpp"
#include "../include/GameBoard.hpp"
#include "../include/getkey.hpp"

const int N = 4;
GameBoard gb(N);

int main()
{
    while (true)
    {
        // Generate new
        gb.generate_new();

        // Clear the console
        clear_console();

        // Show the game board
        gb.show();

        // Operation
        int opt = getkey();
        switch (opt)
        {
        case -1:
            gb.move_up();
            break;
        case -2:
            gb.move_right();
            break;
        case -3:
            gb.move_down();
            break;
        case -4:
            gb.move_left();
            break;
        default:
            break;
        }
    }

    return 0;
}