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
    virtual bool is_white_player() = 0;
    virtual bool is_human() = 0;  
    virtual ~Player(); //destructor
};
#endif