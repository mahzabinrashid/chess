#include "square.h"
#include "piece.h"

Square::Square(int row, int col, Piece *piece)
: row{row}, col{col}, piece{piece} {
}

Piece* Square::get_piece() {
    return piece;
}

void Square::set_piece(Piece *thePiece) {
    piece = thePiece;
}

int Square::get_row() {
    return row;
}

void Square::set_row(int theRow) {
    row = theRow;
}
    
int Square::get_col() {
    return col;
}

void Square::set_col(int theCol) {
    col = theCol;
}