#ifndef PIECE_H
#define PIECE_H
#include "square.h"
#include <string>
using namespace std;


class Piece {
    string name;
    string color;
    vector<Square> valid_moves;
};

#endif