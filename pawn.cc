#include "pawn.h"
#include <vector>
#include <string>

using namespace std;

Pawn::Pawn(string name, bool white) : Piece{name, white} {}

/*void Pawn::valid_moves(Board board, Square initial, Square final) {
    if (board[initial.get_row() + 1][initial.get_col()].get_piece()->get_name() == " " || 
        board[initial.get_row() + 1][initial.get_col()].get_piece()->get_name() == "-") {
        allowed_moves.emplace_back(board_coordinates(initial.get_row() + 1, initial.get_col()));
    } 
}*/

/*bool Pawn::is_valid(string final) {
    for (int i = 0; i < allowed_moves.size(); i++) {
        if (final == allowed_moves[i]) {
            return true;
        }
    } 
    return false;
} */