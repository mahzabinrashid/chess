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
    // this is an abstract class. change new Piece in board class to new King etc.
    string name;
    bool white;
    protected:
    vector<string> allowed_moves; // stores the moves that are allowed
    public:
    Piece(string name, bool white);

    string get_name();
    void set_name(string name);

    bool is_white();
    void set_white(bool white);
};

#endif
