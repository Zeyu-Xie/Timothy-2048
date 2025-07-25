#pragma once

#include <iostream>
#include <vector>

using VINT = std::vector<int>;
using VVINT = std::vector<VINT>;

class GameBoard
{
private:
    int N;
    int step;
    VINT operations;
    VVINT array;

public:
    // Constructors
    GameBoard(int n);
    GameBoard(int n, int step, VINT operations, VVINT array);

    // Class method
    void show();
    int get_step();

    // Game logic
    void generate_new();
    bool is_full();
    bool move_up();
    bool move_right();
    bool move_down();
    bool move_left();

    // Files
    void export_saving(std::string destination);
    void import_saving(std::string destination);
};