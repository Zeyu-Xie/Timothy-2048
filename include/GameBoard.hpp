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
    // Constructor
    GameBoard(int n);

    // Class method
    void show();

    // Game logic
    void generate_new();
    bool is_full();
    void move_up();
    void move_right();
    void move_down();
    void move_left();
};