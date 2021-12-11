#include <iostream>
#include "game.h"

using namespace std;

Game::init(Human p1, Human p2) {
    players.emplace_back(p1);
    players.emplace_back(p2);
    if (p1.is_white_player()) {
        current_player_turn = p1;
    } else {
        current_player_turn = p2;
    }
};

Game::player_move(Human player) {
    if (player != current_player_turn) { //not that player's turn
        cout << "It's not your turn" << endl;
        return false;
    } else {
        if (current_player_turn == players[0]) {
            current_player_turn = players[1];
        } else {
            current_player_turn = players[0];
        }
        return true;
    }
};

Game::~Game() {}