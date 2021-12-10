#include <iostream>
#include "player.h"

using namespace std;

Player::Player(bool white_player, bool human): //constructor
white_player{white_player}, human{human} {}

bool Player::is_whiteplayer() {
    return this->white_player;
}

bool Player::is_human() {
    return this->human;
}

Player::~Player(){} //destructor