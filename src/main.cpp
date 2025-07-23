#define CLEAR_CONSOLE

#define VERSION "1.0.1"

#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "../include/characters.hpp"
#include "../include/clearConsole.hpp"
#include "../include/GameBoard.hpp"
#include "../include/formats.hpp"
#include "../include/utils.hpp"

// Arguments
bool SHOW_HELP = false;
bool SHOW_VERSION = false;
bool IMPORT = false;
bool OUTPUT = false;
std::string IMPORT_PATH = "";
std::string OUTPUT_PATH = "";

// Play game
void game()
{
    // Init
    std::srand(std::time(nullptr));
    int N = 4;
    GameBoard gb(N);
    int step;
    bool generate_new_signal = true;

    // Import
    if (IMPORT)
    {
        gb.import_saving(IMPORT_PATH);
        generate_new_signal = false;
    }

    // Game loop
    while (true)
    {
        bool quit = false;

        // Generate new
        if (generate_new_signal)
            gb.generate_new();
        else
            generate_new_signal = true;

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
            break;
        }

        // Operation
        while (true)
        {
            int opt = getkey();
            bool is_continue_key = false;
            switch (opt)
            {
            // `Q` or `q` (break: ✅)
            case 81:
            case 113:
                is_continue_key = true;
                quit = true;
                break;
            // `S` or `s` (break: ❌)
            case 83:
            case 115:
                gb.export_saving(input("Output path: "));
                break;
            // Up (break: ❓)
            case -1:
                is_continue_key = gb.move_up();
                break;
            // Right (break: ❓)
            case -2:
                is_continue_key = gb.move_right();
                break;
            // Down (break: ❓)
            case -3:
                is_continue_key = gb.move_down();
                break;
            // Left (break: ❓)
            case -4:
                is_continue_key = gb.move_left();
                break;
            // Others
            default:
                break;
            }

            // If illegal operation
            if (is_continue_key)
                break;
        }

        // If quit signal
        if (quit)
            break;
    }

    // Output
    if (OUTPUT)
        gb.export_saving(OUTPUT_PATH);
}

// Show help page
void help()
{
    std::cout << "timothy-2048 - A simple terminal 2048 game by Zeyu Xie\n\n"
              << "Usage:\n"
              << "  timothy-2048 [options]\n\n"
              << "Without any options, the game starts immediately with default settings.\n\n"
              << "Options:\n"
              << "  -h, --help              Show this help message and exit\n"
              << "  -v, --version           Show version information and exit\n\n"
              << "Examples:\n"
              << "  timothy-2048                Start game with default 4x4 board\n"
              << "  timothy-2048 --help         Show help message\n"
              << "  timothy-2048 --version      Show version information\n\n"
              << "Enjoy the game!\n";
}

// Display start animation
void start()
{
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
}

// Show version page
void version()
{
    std::cout << "Timothy 2048 version " << VERSION << "\n";
}

int main(int argc, char *argv[])
{

    // Analyse commands
    if (argc > 1)
    {
        int tot = 1;
        while (tot < argc)
        {
            std::string arg = argv[tot];

            if (arg == "-h" || arg == "--help")
            {
                SHOW_HELP = true;
                tot++;
            }
            else if (arg == "-i" || arg == "--import")
            {
                IMPORT = true;
                if (tot + 1 < argc)
                {
                    IMPORT_PATH = argv[tot + 1];
                    tot += 2;
                }
                else
                {
                    IMPORT_PATH = "";
                    tot++;
                }
            }
            else if (arg == "-o" || arg == "--output")
            {
                OUTPUT = true;
                if (tot + 1 < argc)
                {
                    OUTPUT_PATH = argv[tot + 1];
                    tot += 2;
                }
                else
                {
                    OUTPUT_PATH = "";
                    tot++;
                }
            }
            else if (arg == "-v" || arg == "--version")
            {
                SHOW_VERSION = true;
                tot++;
            }
            else
                tot++;
        }
    }

    // Execute commands
    if (SHOW_HELP)
        help();
    else if (SHOW_VERSION)
        version();
    else
    {
        // Perform start animation
        start();

        // Run the game function
        game();
        std::cout << std::endl;
    }

    return 0;
}