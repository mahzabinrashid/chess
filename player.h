#ifndef __PLAYER_H__
#define __PLAYER_H__

#include<vector>
#include <string>
#include "square.h"

class Board;


using namespace std;

class Player {
    bool winner = false;
    string color;
    bool check = false;
    bool checkmate = false;
    bool enpassant = false;
    bool stalemate = false;
    bool castling = false;
    public:
    Player(string color);     //constructor
    void get_color();         //gets color
    void set_color(string c); //sets color
    ~Player();                //destructor
    void initialize_pieces(string color); //sets the pieces each player conatains in its map structure
};

#endif