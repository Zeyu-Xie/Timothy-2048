#include "../include/GameBoard.hpp"

GameBoard::GameBoard(int n) : N(n), array(n, VINT(n, 0)) {}

void GameBoard::show()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            std::cout << array[i][j] << " ";
        std::cout << std::endl;
    }
}