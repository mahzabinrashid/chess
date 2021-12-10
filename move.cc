#include "move.h"
#include "piece.h"

Move::Move(int col_i, int row_i, int col_f, int row_f, Piece *piece_moved, Piece *piece_killed)
: col_i{col_i}, row_i{row_i}, col_f{col_f}, row_f{row_f}, piece_moved{piece_moved}, piece_killed{piece_killed} {
}

int Move::get_col_i() {
    return col_i;
}

int Move::get_row_i() {
    return row_i;
}
int Move::get_col_f() {
    return col_f;
}
int Move::get_row_f() {
    return row_f;
}

Piece* Move::get_piece_moved() {
    return piece_moved;
}
Piece* Move::get_piece_killed() {
    return piece_killed;
}

void Move::set_col_i(int x) {
    x = col_i;
}
void Move::set_row_i(int x) {
    x = row_i;

}
void Move::set_col_f(int x) {
    x = col_f;

}
void Move::set_row_f(int x) {
    x = row_f;

}

void Move::set_piece_moved(Piece* p) {
    piece_moved = p;

}

void Move::set_piece_killed(Piece* p) {
    piece_killed = p;

}