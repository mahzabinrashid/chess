#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include <string>
#include <vector>
#include "piece.h"
#include "square.h"
#include "board.h"

class Pawn : public Piece {
    string name;
    bool white;
    public: 
	Pawn(string name, bool white);
	void promotion(int row, int col);
	void en_passant(int row, int col);
	void valid_moves(Board board, Square initial, Square final) override; // updates the possible_moves vector with the available moves for the piece
	//bool is_valid(string final) override;
	};


#endif