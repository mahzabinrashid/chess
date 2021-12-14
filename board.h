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
    bool becomes_check;
    void create_board();
    void create_board(bool p1_human, bool p2_human, int p1_level, int p2_level);
    Player get_current_player();
    void update_board(int col_i, int row_i, int col_f, int row_f);
    bool correct_command(char col_i, int row_i, char col_f, int row_f);
    string board_coordinates(int col, int row); // converts the integers into string notation
    vector<string> valid_moves(string name, int col_i, int row_i, int col_f, int row_f); // outputs a vector of the valid moves available
    bool is_valid(int col_i, int row_i, int col_f, int row_f); // has the valid_moves method called inside it
    bool is_check(int col_i, int row_i, int col_f, int row_f); // checks if the king is in check after a piece has been moved
    bool will_be_check(string name, bool white, string final_pos); // checks if the king will be in check after being moved
    bool is_checkmate(int col, int row); 
    // check features remaining: i) opposition piece cannot move because king will be in check (ii) king still in checkmate even if it can capture opposition piece
    bool correct_player(int col_i, int row_i); // checks if the player making the move is the current player
    ~Board(); //destructor
};

#endif