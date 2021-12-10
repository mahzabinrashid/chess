#ifndef _HUMAN_
#define _HUMAN_
#include "player.h"

class Human: public Player {
    public:
    Human(bool white_player, bool human);
    bool is_white_player() override;
    bool is_human() override;  
};

#endif