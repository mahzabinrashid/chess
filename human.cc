#include <iostream>
#include "human.h"

using namespace std;

Human::Human(bool white_player): Player{white_player} {
    this->human = true;
}

