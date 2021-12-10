#include <iostream>
#include "human.h"

using namespace std;

Human::Human(bool white_player, bool human): Student{white_player, human} {
}

 bool Human::is_white_player() {
     return white_player;
 };

bool Human::is_human() {
    return human;
};  
