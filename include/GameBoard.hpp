#pragma once
#include <iostream>
#include <vector>

using VINT = std::vector<int>;
using VVINT = std::vector<VINT>;

class GameBoard
{
private:
    int N;
    VVINT array;

public:
    GameBoard(int n);
    void show();
};