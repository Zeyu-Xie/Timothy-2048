#include <iomanip>
#include <tuple>

#include "../include/GameBoard.hpp"

// Constructor
GameBoard::GameBoard(int n) : N(n), array(n, VINT(n, 0)) {}

// Class method
void GameBoard::show()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << std::right << std::setw(5) << array[i][j] << " ";
        std::cout << std::endl;
    }
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
