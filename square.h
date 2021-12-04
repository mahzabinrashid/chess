#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <string>
#include "piece.h"
class Piece;
using namespace std;

class Square {
    int row;
	int col;
    Piece* piece;
    public:
    Square(int row, int col, Piece* piece);

    Piece* get_piece();
    void set_piece(Piece* p);

    int get_row();
    void set_row(int x);
    
    int get_col();
    void set_col(int y);
};

#endif