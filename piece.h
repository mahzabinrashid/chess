#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include "square.h"
#include "board.h"
class Square;
class Board;

using namespace std;

class Piece {
    string name;
    bool white;
    public:
    Piece(string name, bool white);

    string get_name();
    void set_name(string name);

    bool is_white();
    void set_white(bool white);
    void move(Board board, Square initial, Square final);
};

#endif
