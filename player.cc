#include <iostream>
#include "player.h"

using namespace std;

Player::Player(bool white_player, bool human): //constructor
white_player{white_player}, human{human} {}

 bool Player::is_white_player() {
     return white_player;
 };

bool Player::is_human() {
    return human;
};  

Player::~Player(){} //destructor