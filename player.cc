#include <iostream>
#include "player.h"

using namespace std;

Player::Player(bool white_player, bool human, int level): //constructor
white_player{white_player}, human{human}, level{level} {}

bool Player::is_white_player() {
     return white_player;
 };

 void Player::set_white_player(bool wp) {
    white_player = wp;
 };

bool Player::is_human() {
    return human;
};  

int Player::get_level() {
    return level;
}

Player::~Player(){} //destructor