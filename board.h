#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Board {
    vector<vector<Square>> chess_board;
    Player *white_player;
    Player *black_player;
    void create_board(); //creates an 8x8 chess board
    void create_pieces(); //creates the pieces of a chessboard and displays it
    void create_players(); //creates 2 players and assigns the role of black and white to each player
    bool valid_move(); //checks if the move to be made by a player is valid or not
    void set_observer(); 
    void delete_piece(int row, int col); //removes a piece from the board when a piece is captured
    void update_board(); //renders a new board after a move has been made
    bool get_check(Player *player); //checks if the player is in check
    void set_check(Player *player); //sets a check on the other player
    string board_coordinates(int row, int col); //returns the board notations on the side of the board
};

#endif