#include <iomanip>
#include <tuple>

#include "../include/GameBoard.hpp"

// Constructor
GameBoard::GameBoard(int n) : N(n), array(n, VINT(n, 0)) {}

// Class method
std::string _center(int x, int l)
{
    std::string str = x > 0 ? std::to_string(x) : " ";
    int total_width = l;
    int pad = total_width - str.length();
    int pad_left = pad / 2;
    int pad_right = pad - pad_left;
    return std::string(pad_left, ' ') + str + std::string(pad_right, ' ');
}
void GameBoard::show()
{
    // Top line
    std::string top_line = "\u250C";
    for (int i = 0; i < N - 1; i++)
        top_line += "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u252C";
    top_line += "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2510";

    // Middle line
    std::string middle_line = "\u251C";
    for (int i = 0; i < N - 1; i++)
        middle_line += "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u253C";
    middle_line += "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2524";

    // Bottom line
    std::string bottom_line = "\u2514";
    for (int i = 0; i < N - 1; i++)
        bottom_line += "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2534";
    bottom_line += "\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2518";

    // Space line
    std::string space_line = "\u2502";
    for (int i = 0; i < N; i++)
        space_line += "       \u2502";

    // Draw the first row
    std::cout << top_line << std::endl;
    std::cout << space_line << std::endl;
    std::cout << "\u2502";
    for (int j = 0; j < N; j++)
        std::cout << _center(array[0][j], 7) << "\u2502";
    std::cout << std::endl;
    std::cout << space_line << std::endl;

    // Draw the middle rows
    for (int i = 1; i < N - 1; i++)
    {
        std::cout << middle_line << std::endl;
        std::cout << space_line << std::endl;
        std::cout << "\u2502";
        for (int j = 0; j < N; j++)
            std::cout << _center(array[i][j], 7) << "\u2502";
        std::cout << std::endl;
        std::cout << space_line << std::endl;
    }

    // Draw the last row
    std::cout << middle_line << std::endl;
    std::cout << space_line << std::endl;
    std::cout << "\u2502";
    for (int j = 0; j < N; j++)
        std::cout << _center(array[N - 1][j], 7) << "\u2502";
    std::cout << std::endl;
    std::cout << space_line << std::endl;
    std::cout << bottom_line << std::endl;
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
            if (!array[i][j])
                return false;
    return true;
}

void GameBoard::move_up()
{
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
            }
            if (target > 0 && array[target - 1][col] == array[target][col] && last_merge_row != target - 1)
            {
                array[target - 1][col] *= 2;
                array[target][col] = 0;
                last_merge_row = target - 1;
            }
        }
    }
}

void GameBoard::move_right()
{
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
            }
            if (target < N - 1 && array[row][target + 1] == array[row][target] && last_merge_col != target + 1)
            {
                array[row][target + 1] *= 2;
                array[row][target] = 0;
                last_merge_col = target + 1;
            }
        }
    }
}

void GameBoard::move_down()
{
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
            }
            if (target < N - 1 && array[target + 1][col] == array[target][col] && last_merge_row != target + 1)
            {
                array[target + 1][col] *= 2;
                array[target][col] = 0;
                last_merge_row = target + 1;
            }
        }
    }
}

void GameBoard::move_left()
{
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
            }
            if (target > 0 && array[row][target - 1] == array[row][target] && last_merge_col != target - 1)
            {
                array[row][target - 1] *= 2;
                array[row][target] = 0;
                last_merge_col = target - 1;
            }
        }
    }
}
