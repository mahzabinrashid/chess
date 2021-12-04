#include "square.h"
#include "piece.h"

Piece::Piece(string name, bool white)
: name{name}, white{white} {
}

string Piece::get_name() {
    return name;

}
void Piece::set_name(string theName) {
    name = theName;
}

bool Piece::is_white() {
    return white;
}
void Piece::set_white(bool theWhite) {
    white = theWhite;
}






