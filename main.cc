#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "board.h"
using namespace std;

int get_row_int(char row_char) {
    int row_int;
    if (row_char == 'a') row_int = 0;
	if (row_char == 'b') row_int = 1;
	if (row_char == 'c') row_int = 2;
	if (row_char == 'd') row_int = 3;
	if (row_char == 'e') row_int = 4;
	if (row_char == 'f') row_int = 5;
	if (row_char == 'g') row_int = 6;
	if (row_char == 'h') row_int = 7;
    return row_int;
}

int main() {
    string command;
    Board b;
    b.create_board();
    while (cin >> command) {
        if (command == "move") {
            char read_initial_row, read_final_row;
            int read_initial_col, read_final_col, initial_row, final_row, initial_col, final_col;
            cin >> read_initial_row >> read_initial_col >> read_final_row >> read_final_col;
            
            initial_row = get_row_int(read_initial_row);
            final_row = get_row_int(read_final_row);
            initial_col = read_initial_col - 1;
            final_col = read_final_col - 1;
            
            if (true) { // if valid_move is true
                b.update_board(initial_row, final_row, initial_col, final_col);
            }
        }
    }
}