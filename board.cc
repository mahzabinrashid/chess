#include "board.h"
#include <string>
using namespace std;

string board_coordinates(int row, int col) {
    string notation;
    if (row == 0 && col == 1) notation = "a";
    if (row == 0 && col == 2) notation = "b";
    if (row == 0 && col == 3) notation = "c";
    if (row == 0 && col == 4) notation = "d";
    if (row == 0 && col == 5) notation = "e";
    if (row == 0 && col == 6) notation = "f";
    if (row == 0 && col == 7) notation = "g";
    if (row == 0 && col == 8) notation = "h";
    if (row == 1 && col == 0) notation = "1";
    if (row == 2 && col == 0) notation = "2";
    if (row == 3 && col == 0) notation = "3";
    if (row == 4 && col == 0) notation = "4";
    if (row == 5 && col == 0) notation = "5";
    if (row == 6 && col == 0) notation = "6";
    if (row == 7 && col == 0) notation = "7";
    if (row == 8 && col == 0) notation = "8";
    return notation;
}

