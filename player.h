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
    int level;
    public:
    Player(bool white_player, bool human, int level); //constructor
    bool is_white_player();
    bool is_human();  
    int get_level();
    ~Player(); //destructor
};
#endif