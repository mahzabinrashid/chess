#include <iostream>
#include "board.h"
#include "square.h"
#include "piece.h"
#include <vector>

using namespace std;

void Board::create_board() {
    // creates the initial checkerboard
    for (int i = 0; i < 8; i++) {
        vector<Square> k;
        for (int j = 0; j < 8; j++){
            if ( (i+j) % 2 == 0 ) {
                k.emplace_back(Square(i, j, new Piece(" ",false)));
            } else {
                k.emplace_back(Square(i, j, new Piece("-",false)));
            }
        }
        box.emplace_back(k);
    }
    // fills checkerboard with pieces
    box[7][0] = Square(7, 0, new Piece("r",false));
    box[7][1] = Square(7, 1, new Piece("n",false));
    box[7][2] = Square(7, 2, new Piece("b",false));
    box[7][3] = Square(7, 3, new Piece("q",false));
    box[7][4] = Square(7, 4, new Piece("k",false));
    box[7][5] = Square(7, 5, new Piece("b",false));
    box[7][6] = Square(7, 6, new Piece("n",false));
    box[7][7] = Square(7, 7, new Piece("r",false));

    box[0][0] = Square(0, 0, new Piece("R",true));
    box[0][1] = Square(0, 1, new Piece("N",true));
    box[0][2] = Square(0, 2, new Piece("B",true));
    box[0][3] = Square(0, 3, new Piece("Q",true));
    box[0][4] = Square(0, 4, new Piece("K",true));
    box[0][5] = Square(0, 5, new Piece("B",true));
    box[0][6] = Square(0, 6, new Piece("N",true));
    box[0][7] = Square(0, 7, new Piece("R",true)); 


    for (int i = 0; i < 8; i++) {
        box[6][i] = Square(6, i, new Piece("p",false));
    }
    for (int i = 0; i < 8; i++) {
        box[1][i] = Square(6, i, new Piece("P",true));
    }

    // prints final checkerboard 
    for (std::size_t i = box.size(); i > 0; --i) {
        for (std::size_t j = 0; j < box[i - 1].size(); ++j) {
            cout << box[i - 1][j].get_piece()->get_name(); 
        }
        cout << endl;
    }  
}

void Board::update_board(Square initial, Square final, Piece piece) {
 //   box[0][0] = Square(0, 0, new Piece("R",true));
   
    for (std::size_t i = box.size(); i > 0; --i) {
        for (std::size_t j = 0; j < box[i - 1].size(); ++j) {
            cout << box[i - 1][j].get_piece()->get_name(); 
        }
        cout << endl;
    }  
}