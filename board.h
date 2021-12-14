#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "square.h"
#include "player.h"
class Square;

using namespace std;

class Board {
    vector<vector<Square>> board;
    vector<Player> players;
    Player current_player{true, true, 0};
    public:
    // setup methods 
    void print_initial_board();
    void initialise_players(bool p1_human, bool p2_human, int p1_level, int p2_level);
    void put_piece(string piece, int final_col, int final_row);
    void delete_piece(int final_col, int final_row);
    void setup_board();
    bool valid_setup();
    void create_board();
    void change_current_player(bool white);
    Player get_current_player();
    void update_board(int col_i, int row_i, int col_f, int row_f);
    bool correct_command(char col_i, int row_i, char col_f, int row_f);
    string board_coordinates(int col, int row); // converts the integers into string notation
    vector<string> valid_moves(string name, int col_i, int row_i, int col_f, int row_f); // outputs a vector of the valid moves available
    bool is_valid(int col_i, int row_i, int col_f, int row_f); // has the valid_moves method called inside it
    bool is_check(int col_i, int row_i, int col_f, int row_f); // checks if the king is in check after a piece has been moved
    bool correct_player(int col_i, int row_i); // checks if the player making the move is the current player
    ~Board(); //destructor
};

#endif