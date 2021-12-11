#include <iostream>
#include "game.h"

using namespace std;

Game::init(Player p1, Player p2) {
    players.emplace_back(p1);
    players.emplace_back(p2);
    board.create_board();
    if (p1.is_white_player()) {
        current_player_turn = p1;
    } else {
        current_player_turn = p2;
    }
};

Game::player_move(Player player, int col_i, int row_i, int col_f, int row_f) {
    Piece* source_piece = board[row_i][col_i].get_piece();
    Piece* dest_piece = board[row_f][col_f].get_piece();
    if (player != current_player_turn) { //not that player's turn
        cout << "It's not your turn" << endl;
        return false;
    } else {
        if (this->current_player_turn == players[0]) {
            this->current_player_turn = players[1];
        } else {
            this->current_player_turn = players[0];
        }
        return true;
    }
};

Game::~Game() {}