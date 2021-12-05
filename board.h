#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "square.h"
class Square;

using namespace std;

class Board {
    vector<vector<Square>> box;
    public:
    void create_board();
    void update_board();
};

#endif