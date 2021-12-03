#include <iostream>
#include "board.h"
#include "player.h"

Player Player::get_color() { return color; }
Player Player::set_color(string c) { color = c; }

void Player::initialize_pieces(string color) {
    if (color == "white") {
        pieces["a1"] = "R";
        pieces["b1"] = "N";
        pieces["c1"] = "B";
        pieces["d1"] = "Q";
        pieces["e1"] = "K";
        pieces["f1"] = "B";
        pieces["g1"] = "N";
        pieces["h1"] = "R";
        pieces["a2"] = "P";
        pieces["b2"] = "P";
        pieces["c2"] = "P";
        pieces["d2"] = "P";
        pieces["e2"] = "P";
        pieces["f2"] = "P";
        pieces["g2"] = "P";
        pieces["h2"] = "P";
    } else if (color == "black") {
        pieces["a8"] = "r";
        pieces["b8"] = "n";
        pieces["c8"] = "b";
        pieces["d8"] = "q";
        pieces["e8"] = "k";
        pieces["f8"] = "b";
        pieces["g8"] = "n";
        pieces["h8"] = "r";
        pieces["a7"] = "p";
        pieces["b7"] = "p";
        pieces["c7"] = "p";
        pieces["d7"] = "p";
        pieces["e7"] = "p";
        pieces["f7"] = "p";
        pieces["g7"] = "p";
        pieces["h7"] = "p";
    }
}
