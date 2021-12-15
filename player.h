#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<vector>
#include <string>

class Board;

using namespace std;

class Player {
    protected: 
    bool white;
    bool human;
    int level;
    public:
    Player(bool white, bool human, int level); // constructor

    void set_white(bool w);
    bool is_white();

    void set_human(bool h); 
    bool is_human(); 

    void set_level(int l); 
    int get_level();
    
    ~Player(); // destructor
};
#endif