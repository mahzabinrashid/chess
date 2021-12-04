#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "square.h"

using namespace std;

class Board {
    vector<vector<Square>> box;
    public:
    void create_board();
};

#endif