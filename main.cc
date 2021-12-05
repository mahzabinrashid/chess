#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "board.h"
using namespace std;

int main() {
    string command;
    Board b;
    b.create_board();
    while (cin >> command) {
        if (command == "move") {
            char initial_row, final_row;
            int initial_col, final_col;
            cin >> initial_row >> initial_col >> final_row >> final_col;
            cout <<  initial_row;
            if (true) { // if valid_move is true
                b.update_board();
            }
        }
    }
}