#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "../include/characters.hpp"
#include "../include/clearConsole.hpp"
#include "../include/GameBoard.hpp"
#include "../include/getkey.hpp"
#include "../include/formats.hpp"

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
                is_legal = gb.move_up();
                break;
            case -2:
                is_legal = gb.move_right();
                break;
            case -3:
                is_legal = gb.move_down();
                break;
            case -4:
                is_legal = gb.move_left();
                break;
            default:
                is_legal = false;
                break;
            }

            // If legal key pressed
            if (is_legal)
                break;
        }
    }

    return steps;
}

int main()
{
    // Program start animation
    clear_console();
    std::cout << std::endl
              << "  \033[0;1;33;93m\u2584\u2584\033[0;1;32;92m\u2584\u2584\033[0;1;36;96m\u2584\033[0m      \033[0;1;31;91m\u2584\033[0;1;33;93m\u2584\u2584\033[0;1;32;92m\u2584\033[0m        \033[0;1;31;91m\u2584\033[0;1;33;93m\u2584\u2584\033[0m     \033[0;1;34;94m\u2584\033[0;1;35;95m\u2584\u2584\033[0;1;31;91m\u2584\033[0m" << std::endl
              << " \033[0;1;33;93m\u2588\033[0;1;32;92m\u2580\u2580\033[0;1;36;96m\u2580\u2580\033[0;1;34;94m\u2588\u2588\033[0;1;35;95m\u2584\033[0m   \033[0;1;33;93m\u2588\u2588\033[0;1;32;92m\u2580\u2580\033[0;1;36;96m\u2588\u2588\033[0m      \033[0;1;33;93m\u2584\u2588\033[0;1;32;92m\u2588\u2588\033[0m   \033[0;1;34;94m\u2584\033[0;1;35;95m\u2588\u2588\033[0;1;31;91m\u2580\u2580\033[0;1;33;93m\u2588\u2588\033[0;1;32;92m\u2584\033[0m" << std::endl
              << "       \033[0;1;35;95m\u2588\033[0;1;31;91m\u2588\033[0m  \033[0;1;33;93m\u2588\033[0;1;32;92m\u2588\033[0m    \033[0;1;34;94m\u2588\033[0;1;35;95m\u2588\033[0m    \033[0;1;33;93m\u2588\033[0;1;32;92m\u2580\033[0m \033[0;1;36;96m\u2588\u2588\033[0m   \033[0;1;35;95m\u2588\033[0;1;31;91m\u2588\u2584\033[0m  \033[0;1;32;92m\u2584\u2588\033[0;1;36;96m\u2588\033[0m" << std::endl
              << "     \033[0;1;35;95m\u2584\033[0;1;31;91m\u2588\u2580\033[0m   \033[0;1;32;92m\u2588\033[0;1;36;96m\u2588\033[0m \033[0;1;34;94m\u2588\u2588\033[0m \033[0;1;35;95m\u2588\033[0;1;31;91m\u2588\033[0m  \033[0;1;33;93m\u2584\033[0;1;32;92m\u2588\u2580\033[0m  \033[0;1;34;94m\u2588\u2588\033[0m    \033[0;1;33;93m\u2588\u2588\033[0;1;32;92m\u2588\u2588\033[0;1;36;96m\u2588\u2588\033[0m" << std::endl
              << "   \033[0;1;35;95m\u2584\033[0;1;31;91m\u2588\u2580\033[0m     \033[0;1;36;96m\u2588\033[0;1;34;94m\u2588\033[0m    \033[0;1;31;91m\u2588\033[0;1;33;93m\u2588\033[0m  \033[0;1;32;92m\u2588\033[0;1;36;96m\u2588\u2588\033[0;1;34;94m\u2588\u2588\033[0;1;35;95m\u2588\u2588\033[0;1;31;91m\u2588\033[0m  \033[0;1;33;93m\u2588\033[0;1;32;92m\u2588\u2580\033[0m  \033[0;1;34;94m\u2580\u2588\033[0;1;35;95m\u2588\033[0m" << std::endl
              << " \033[0;1;35;95m\u2584\033[0;1;31;91m\u2588\u2588\033[0;1;33;93m\u2584\u2584\033[0;1;32;92m\u2584\u2584\033[0;1;36;96m\u2584\033[0m   \033[0;1;35;95m\u2588\u2588\033[0;1;31;91m\u2584\u2584\033[0;1;33;93m\u2588\u2588\033[0m        \033[0;1;31;91m\u2588\u2588\033[0m   \033[0;1;32;92m\u2580\033[0;1;36;96m\u2588\u2588\033[0;1;34;94m\u2584\u2584\033[0;1;35;95m\u2588\u2588\033[0;1;31;91m\u2580\033[0m" << std::endl
              << " \033[0;1;31;91m\u2580\033[0;1;33;93m\u2580\u2580\033[0;1;32;92m\u2580\u2580\033[0;1;36;96m\u2580\u2580\033[0;1;34;94m\u2580\033[0m    \033[0;1;31;91m\u2580\033[0;1;33;93m\u2580\u2580\033[0;1;32;92m\u2580\033[0m         \033[0;1;33;93m\u2580\u2580\033[0m     \033[0;1;34;94m\u2580\033[0;1;35;95m\u2580\u2580\033[0;1;31;91m\u2580\033[0m" << std::endl
              << std::endl
              << std::endl
              << bold(color_16_foreground("Welcome to Timothy-2048. \u00A9 Zeyu Xie.", 3)) << std::endl
              << std::flush;
    sleep(3);
    clear_console();

    // Run the game function
    int steps = game();
    std::cout << steps << std::endl;

    return 0;
}