#include <cmath>
#include <iomanip>
#include <map>
#include <tuple>

#include "../include/GameBoard.hpp"
#include "../include/formats.hpp"

// Constructor
GameBoard::GameBoard(int n) : N(n), step(0), array(n, VINT(n, 0)) {}
GameBoard::GameBoard(int n, int step, VVINT array) : N(n), step(step), array(array) {}

// Class method
const std::map<int, int> value_colors = {{2, 124}, {4, 160}, {8, 196}, {16, 202}, {32, 208}, {64, 214}, {128, 220}, {256, 226}, {512, 190}, {1024, 154}, {2048, 118}, {4096, 82}, {8192, 51}, {16384, 45}, {32768, 39}, {65536, 33}, {131072, 27}};
inline int _value_to_color(int x)
{
    return value_colors.at(x);
}
std::string _center_colored(int x, int l)
{
    std::string str = x > 0 ? std::to_string(x) : " ";
    int total_width = l;
    int pad = total_width - str.length();
    int pad_left = pad / 2;
    int pad_right = pad - pad_left;
    return x > 0 ? std::string(pad_left, ' ') + bold(color_256_foreground(str, _value_to_color(x))) + std::string(pad_right, ' ') : std::string(pad_left, ' ') + str + std::string(pad_right, ' ');
}
void GameBoard::show()
{
    // Top line
    std::string top_line = "\u2554";
    for (int i = 0; i < N - 1; i++)
        top_line += "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2566";
    top_line += "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2557";

    // Middle line
    std::string middle_line = "\u2560";
    for (int i = 0; i < N - 1; i++)
        middle_line += "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u256C";
    middle_line += "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2563";

    // Bottom line
    std::string bottom_line = "\u255A";
    for (int i = 0; i < N - 1; i++)
        bottom_line += "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u2569";
    bottom_line += "\u2550\u2550\u2550\u2550\u2550\u2550\u2550\u255D";

    // Space line
    std::string space_line = "\u2551";
    for (int i = 0; i < N; i++)
        space_line += "       \u2551";

    // Draw the first row
    std::cout << top_line << std::endl
              << space_line << std::endl;
    std::cout << "\u2551";
    for (int j = 0; j < N; j++)
        std::cout << _center_colored(array[0][j], 7) << "\u2551";
    std::cout << std::endl
              << space_line << std::endl;

    // Draw the middle rows
    for (int i = 1; i < N - 1; i++)
    {
        std::cout << middle_line << std::endl
                  << space_line << std::endl;
        std::cout << "\u2551";
        for (int j = 0; j < N; j++)
            std::cout << _center_colored(array[i][j], 7) << "\u2551";
        std::cout << std::endl
                  << space_line << std::endl;
    }

    // Draw the last row
    std::cout << middle_line << std::endl
              << space_line << std::endl;
    std::cout << "\u2551";
    for (int j = 0; j < N; j++)
        std::cout << _center_colored(array[N - 1][j], 7) << "\u2551";
    std::cout << std::endl;
    std::cout << space_line << std::endl
              << bottom_line << std::endl;

    // Print the data
    std::cout << std::endl
              << color_256_background("> Steps: " + std::to_string(step) + " <", 184) << std::endl
              << std::endl;
}

int GameBoard::get_step()
{
    return step;
}

// Game logic
void GameBoard::generate_new()
{
    std::vector<std::tuple<int, int>> empty_coord;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!array[i][j])
                empty_coord.push_back({i, j});
    if (!empty_coord.empty())
    {
        auto [row, col] = empty_coord[rand() % empty_coord.size()];
        array[row][col] = (rand() % 10 == 0) ? 4 : 2;
    }
}

bool GameBoard::is_full()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (array[i][j] == 0)
                return false;
            // Right
            if (j + 1 < N && array[i][j] == array[i][j + 1])
                return false;
            // Down
            if (i + 1 < N && array[i][j] == array[i + 1][j])
                return false;
        }
    return true;
}

bool GameBoard::move_up()
{
    bool moved = false;
    for (int col = 0; col < N; ++col)
    {
        int last_merge_row = -1;
        for (int row = 1; row < N; ++row)
        {
            if (array[row][col] == 0)
                continue;
            int target = row;
            while (target > 0 && array[target - 1][col] == 0)
            {
                array[target - 1][col] = array[target][col];
                array[target][col] = 0;
                --target;
                moved = true;
            }
            if (target > 0 && array[target - 1][col] == array[target][col] && last_merge_row != target - 1)
            {
                array[target - 1][col] *= 2;
                array[target][col] = 0;
                last_merge_row = target - 1;
                moved = true;
            }
        }
    }
    if (moved)
        step++;
    return moved;
}

bool GameBoard::move_right()
{
    bool moved = false;
    for (int row = 0; row < N; ++row)
    {
        int last_merge_col = N;
        for (int col = N - 2; col >= 0; --col)
        {
            if (array[row][col] == 0)
                continue;
            int target = col;
            while (target < N - 1 && array[row][target + 1] == 0)
            {
                array[row][target + 1] = array[row][target];
                array[row][target] = 0;
                ++target;
                moved = true;
            }
            if (target < N - 1 && array[row][target + 1] == array[row][target] && last_merge_col != target + 1)
            {
                array[row][target + 1] *= 2;
                array[row][target] = 0;
                last_merge_col = target + 1;
                moved = true;
            }
        }
    }
    if (moved)
        step++;
    return moved;
}

bool GameBoard::move_down()
{
    bool moved = false;
    for (int col = 0; col < N; ++col)
    {
        int last_merge_row = N;
        for (int row = N - 2; row >= 0; --row)
        {
            if (array[row][col] == 0)
                continue;
            int target = row;
            while (target < N - 1 && array[target + 1][col] == 0)
            {
                array[target + 1][col] = array[target][col];
                array[target][col] = 0;
                ++target;
                moved = true;
            }
            if (target < N - 1 && array[target + 1][col] == array[target][col] && last_merge_row != target + 1)
            {
                array[target + 1][col] *= 2;
                array[target][col] = 0;
                last_merge_row = target + 1;
                moved = true;
            }
        }
    }
    if (moved)
        step++;
    return moved;
}

bool GameBoard::move_left()
{
    bool moved = false;
    for (int row = 0; row < N; ++row)
    {
        int last_merge_col = -1;
        for (int col = 1; col < N; ++col)
        {
            if (array[row][col] == 0)
                continue;
            int target = col;
            while (target > 0 && array[row][target - 1] == 0)
            {
                array[row][target - 1] = array[row][target];
                array[row][target] = 0;
                --target;
                moved = true;
            }
            if (target > 0 && array[row][target - 1] == array[row][target] && last_merge_col != target - 1)
            {
                array[row][target - 1] *= 2;
                array[row][target] = 0;
                last_merge_col = target - 1;
                moved = true;
            }
        }
    }
    if (moved)
        step++;
    return moved;
}
