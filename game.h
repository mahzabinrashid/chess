#ifndef _GAME_
#define _GAME_
#include "human.h"
#include <vector>
#include <memory>

class Game {
    vector<Human> players;
    Human current_player_turn;
    void init(Human p1, Human p2);
    public:
    bool player_move(Human player, int col_i, int row_i, int col_f, int row_f);
    ~Game();
};

#endif