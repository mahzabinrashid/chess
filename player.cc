#include <iostream>
#include "player.h"

using namespace std;

Player::Player(bool white_player, bool human): //constructor
white_player{white_player}, human{human} {}

Player::~Player(){} //destructor