#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<vector>
#include <string>

class Board;

using namespace std;

class Player {
    protected: 
    bool white_player;
    bool human;
    public:
    Player(bool white_player, bool human); //constructor
    bool is_white_player();
    bool is_human();  
    ~Player(); //destructor
};
#endif