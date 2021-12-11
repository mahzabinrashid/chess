#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "board.h"
#include "player.h"
using namespace std;

int get_col_int(char row_char) {
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
    bool p1 = true; // player human 
    bool p2 = true; // player human
    int p1_level = 0; // human is 0
    int p2_level = 0;   
    Board b;  
    while (cin >> command) {
        if (command == "game") {
            string player_1, player_2;
            cin >>  player_1 >> player_2;
            string ai ("computer");
            if (player_1.find(ai) != string::npos) {
                p1 = false; // player computer
                char l = player_1.at(9);
                p1_level = l - '0';
            } 
            if (player_2.find(ai) != string::npos) {
                p2 = false; // player computer
                char l = player_2.at(9);
                p2_level = l - '0';
            } 
            vector<Player> players;
            players.emplace_back(Player(true, p1, p1_level));
            players.emplace_back(Player(false, p2, p2_level));
            cout << players[1].is_white_player() << endl;
    cout << players[1].is_human() << endl;
    cout << players[1].get_level() << endl;
            Player current_player{true, p1, p1_level};
            Board b{players, current_player};
            b.create_board();
        } else if (command == "move") {
            char read_initial_col, read_final_col;
            int read_initial_row, read_final_row, initial_row, final_row, initial_col, final_col;
            cin >> read_initial_col >> read_initial_row >> read_final_col >> read_final_row;
            
            initial_col = get_col_int(read_initial_col);
            final_col = get_col_int(read_final_col);
            initial_row = read_initial_row - 1;
            final_row = read_final_row - 1;
            
            if (!(b.correct_command(read_initial_col, read_initial_row, read_final_col, read_final_row))) {
                cout << "Incorrect position" << endl;
            } else if (!b.correct_player(initial_col, initial_row)) {
                cout << "Not this players turn" << endl;
            } else if (!(b.is_valid(initial_col, initial_row, final_col, final_row))) {
                cout << "Cannot move piece there" << endl;
            } else {
                b.update_board(initial_col, initial_row, final_col, final_row);
            }
        } else if (command == "resign") {
            cout << "opponent wins" << endl;
        }
        // reset all values 
        p1 = true; 
        p2 = true; 
        p1_level = 0; 
        p2_level = 0; 
    }
    
}