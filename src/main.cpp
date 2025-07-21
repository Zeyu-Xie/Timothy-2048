#include <cstdlib>
#include <ctime>

#include "../include/characters.hpp"
#include "../include/clearConsole.hpp"
#include "../include/GameBoard.hpp"
#include "../include/getkey.hpp"

const int N = 4;
GameBoard gb(N);

int game()
{
    // Init
    std::srand(std::time(nullptr));
    int steps = 0;

    while (true)
    {
        // Evaluate if the game ends
        if (gb.is_full())
        {
            clear_console();
            std::cout << "Game ends. You played " << steps << (steps > 1 ? " steps!" : " step!") << std::endl;
            return steps;
        }

        // Generate new
        gb.generate_new();

        // Clear the console
        clear_console();

        // Show the game board
        gb.show();

        // Operation
        int opt = 0;
        while (true)
        {
            opt = getkey();
            bool is_legal = true;
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
                is_legal = false;
                break;
            }

            // If legal key pressed
            if (is_legal)
            {
                steps++;
                break;
            }
        }
    }

    return steps;
}

int main()
{
    int steps = game();
    std::cout << steps << std::endl;
    return 0;
}