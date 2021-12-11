#ifndef _GAME_
#define _GAME_
#include "player.h"
#include <vector>
#include <memory>

class Game {
    vector<Player> players;
    Player current_player_turn;
    void init(Player p1, Player p2);
    public:
    bool player_move(Player player, int col_i, int row_i, int col_f, int row_f);
    ~Game();
};

#endif

