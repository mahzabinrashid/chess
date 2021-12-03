#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<vector>
#include <string>

class Board;

using namespace std;

class Player {
    bool winner = false;
    vector<Square> move_history;
    string color;
    bool check = false;
    bool checkmate = false;
    bool enpassant = false;
    bool stalemate = false;
    bool castling = false;
    public:
    void get_color();         //gets color
    void set_color(string c); //sets color
};

#endif