#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "square.h"
#include "player.h"
#include "window.h"
class Square;

using namespace std;

class Board {
    vector<vector<Square>> board;
    vector<Player> players;
    Player current_player{true, true, 0};
    Xwindow w; 
    public:
    bool becomes_check;
    bool w_pawn_promotion;
    bool b_pawn_promotion;
    // methods
    void empty_board(); // allocates memory for the empty board
    void initialise_players(bool p1_human, bool p2_human, int p1_level, int p2_level); // initialising the 2 players
    void update_board(int col_i, int row_i, int col_f, int row_f);
    void graphic_print(); // displays graphical interface

    // setup methods
    void put_piece(string piece, int final_col, int final_row); // +
    void delete_piece(int final_col, int final_row); // -
    void setup_board(); // sets up an empty board and prints the board, initialises the 2 players and
    bool valid_setup(); // checks if the setup is valid
    void change_current_player(bool white);

    // default game methods
    void default_board();
    

    // getters and settors
    Player get_current_player();
    void set_current_player(bool white);

    // valid moves
    vector<string> valid_moves(string name, int col_i, int row_i, int col_f, int row_f); // outputs a vector of the valid moves available
    bool is_valid(int col_i, int row_i, int col_f, int row_f); // has the valid_moves method called inside it
    bool correct_command(char col_i, int row_i, char col_f, int row_f);
    bool correct_player(int col_i, int row_i); // checks if the player making the move is the current player
    bool empty_square(int initial_col, int initial_row); // checks if the initial square is empty

    
    // check
    bool is_check(bool white); // checks if the king is in check after a piece has been moved
    bool will_be_check(string name, bool white, string final_pos); // checks if the king will be in check after being moved

    // checkmate
    bool is_checkmate(bool white); 
    // check features remaining: i) opposition piece cannot move because king will be in check (ii) king still in checkmate even if it can capture opposition piece

    // stalemate
    bool is_stalemate(bool white);
    // pawn promotion
    bool white_pawn_promotion(int col_i, int row_i);
    bool black_pawn_promotion(int col_i, int row_i);
    void replace_pawn(string piece, bool white,int col_f, int row_f);

    // level 1
    void level_1(bool white);

    ~Board(); //destructor
};

#endif