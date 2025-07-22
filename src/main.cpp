#define CLEAR_CONSOLE

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
    int step;

    while (true)
    {
        // Generate new
        gb.generate_new();

        // Clear the console
#ifdef CLEAR_CONSOLE
        clear_console();
#endif

        // Show the game board
        gb.show();

        // Evaluate if the game ends
        if (gb.is_full())
        {
            step = gb.get_step();
            std::cout << "Game ends. You played " << step << (step > 1 ? " steps!" : " step!") << std::endl;
            return step;
        }

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

    return step;
}

int main()
{
    // Program start animation
#ifdef CLEAR_CONSOLE
    clear_console();
#endif
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
    sleep(1);
#ifdef CLEAR_CONSOLE
    clear_console();
#endif

    // Run the game function
    game();
    std::cout << std::endl;

    return 0;
}