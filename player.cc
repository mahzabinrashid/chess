#include <iostream>
#include "player.h"

using namespace std;

Player::Player(bool white, bool human, int level): 
white{white}, human{human}, level{level} {}

void Player::set_white(bool w) {
    white = w;
 };

bool Player::is_white() {
     return white;
 };

void Player::set_human(bool h) {
    human = h;
}

bool Player::is_human() {
    return human;
};  

void Player::set_level(int l) {
    level = l;
}

int Player::get_level() {
    return level;
}

Player::~Player(){} 

