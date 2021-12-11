#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "square.h"
#include "move.h"
class Square;
class Move;

using namespace std;

class Board {
    vector<vector<Square>> board;
    vector<Move> move_history;
    public:
    void create_board();
    void update_board(int col_i, int row_i, int col_f, int row_f);
};

#endif