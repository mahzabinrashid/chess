#ifndef MOVE_H
#define MOVE_H
#include <iostream>
#include <string>
#include <vector>
#include "square.h"
#include "player.h"
#include "piece.h"

using namespace std;
class Piece; 

class Move {
    int col_i;
    int row_i;
    int col_f;
    int row_f;
    Piece *piece_moved;
    Piece *piece_killed;
    public:
    Move(int col_i, int row_i, int col_f, int row_f, Piece *piece_moved, Piece *piece_killed);
    int get_col_i();
    int get_row_i();
    int get_col_f();
    int get_row_f();
    Piece* get_piece_moved();
    Piece* get_piece_killed();

    void set_col_i(int x);
    void set_row_i(int x);
    void set_col_f(int x);
    void set_row_f(int x);
    void set_piece_moved(Piece* p);
    void set_piece_killed(Piece* p);
    
};

#endif