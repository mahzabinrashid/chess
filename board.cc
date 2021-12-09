#include <iostream>
#include "board.h"
#include "square.h"
#include "piece.h"
#include <vector>

using namespace std;

void print(vector<vector<Square>> board) {
    // prints final checkerboard 
    for (std::size_t i = board.size(); i > 0; --i) {
        for (std::size_t j = 0; j < board[i - 1].size(); ++j) {
            cout << board[i - 1][j].get_piece()->get_name(); 
        }
        cout << endl;
    }  
}

void Board::create_board() {
    // creates the initial checkerboard
    for (int i = 0; i < 8; i++) {
        vector<Square> k;
        for (int j = 0; j < 8; j++){
            if ( (i + j) % 2 == 0 ) {
                // shared pointer to no_piece
                k.emplace_back(Square(i, j, new Piece("-", false)));
            } else {
                k.emplace_back(Square(i, j, new Piece(" ", false)));
            }
        }
        board.emplace_back(k);
    }
    // fills checkerboard with pieces
    board[7][0] = Square(7, 0, new Piece("r",false));
    board[7][1] = Square(7, 1, new Piece("n",false));
    board[7][2] = Square(7, 2, new Piece("b",false));
    board[7][3] = Square(7, 3, new Piece("q",false));
    board[7][4] = Square(7, 4, new Piece("k",false));
    board[7][5] = Square(7, 5, new Piece("b",false));
    board[7][6] = Square(7, 6, new Piece("n",false));
    board[7][7] = Square(7, 7, new Piece("r",false));

    board[0][0] = Square(0, 0, new Piece("R",true));
    board[0][1] = Square(0, 1, new Piece("N",true));
    board[0][2] = Square(0, 2, new Piece("B",true));
    board[0][3] = Square(0, 3, new Piece("Q",true));
    board[0][4] = Square(0, 4, new Piece("K",true));
    board[0][5] = Square(0, 5, new Piece("B",true));
    board[0][6] = Square(0, 6, new Piece("N",true));
    board[0][7] = Square(0, 7, new Piece("R",true)); 

    for (int i = 0; i < 8; i++) {
        board[6][i] = Square(6, i, new Piece("p",false));
    }
    for (int i = 0; i < 8; i++) {
        board[1][i] = Square(6, i, new Piece("P",true));
    }
    print(board);
}

void Board::update_board(int row_initial, int row_final, int col_initial, int col_final) {
    board[col_final][row_final].set_piece(board[col_initial][row_initial].get_piece());
    if ( (row_initial + col_initial) % 2 == 0 ) {
        board[col_initial][row_initial].set_piece(new Piece("-", false));
    } else {
        board[col_initial][row_initial].set_piece(new Piece(" ", false));
    } 
    print(board);
} 