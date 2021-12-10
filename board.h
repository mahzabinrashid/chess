#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "square.h"
class Square;

using namespace std;

class Board {
    vector<vector<Square>> board;
    public:
    void create_board();
    void update_board(int col_i, int row_i, int col_f, int row_f);
};

#endif