#include "../include/GameBoard.hpp"

#include <iomanip>
#include <tuple>

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