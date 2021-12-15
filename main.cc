#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "board.h"

using namespace std;

// helper function
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
  Board b;

  // player initialisation
  bool p1_human = true; // player human 
  bool p2_human = true; // player human
  int p1_level = 0; // human is 0
  int p2_level = 0;

  // setup
  bool setup = false;
  bool manual_setup = false;
  bool not_custom_b = true;

  // scoreboard
  int score_w = 0;
  int score_b = 0;

  string command;
  while (cin >> command) {
    if (command == "setup") {
      manual_setup = true;
      if (not_custom_b == true) {
        b.setup_board();
        setup = true;
      } else {
        cout << "Cannot enter setup mode in the middle of a game" << endl;
      }
    } else if (command == "+") {
      if (setup == true) {
        string piece;
        char read_col;
        int read_row, final_row, final_col;
        cin >> piece >> read_col >> read_row;
        final_col = get_col_int(read_col);
        final_row = read_row - 1;
        b.put_piece(piece, final_col, final_row);
      } else {
        cout << "Enter setup mode by typing 'setup' to enter setup mode before using this command." << endl;
      }
    } else if (command == "-") {
      if (setup == true) {
        char read_col;
        int read_row, final_row, final_col;
        cin >> read_col >> read_row;
        final_col = get_col_int(read_col);
        final_row = read_row - 1;
        b.delete_piece(final_col, final_row);
      } else {
        cout << "Enter setup mode by typing 'setup' to enter setup mode before using this command." << endl;
      }
    } else if (command == "=") { 
      if (setup == true) {
        string colour;
        bool wp;
        cin >> colour;
        if (colour == "white") {
          wp = true;
        } else {
          wp = false;
        }
        b.change_current_player(wp);
      } else {
        cout << "Enter setup mode by typing 'setup' to enter setup mode before using this command." << endl;
      }
    } else if (command == "done") {
      if (setup == true) {
        if (b.valid_setup()) {
          cout << "Setup successfully completed. Now you can start a game." << endl;
        } else {
          cout << "Please ensure you meet the criteria for a valid setup." << endl;
        }
      } else {
        cout << "Enter setup mode by typing 'setup' to enter setup mode before using this command." << endl;
      }
    } else if (command == "game") {
      string player_1, player_2;
      cin >> player_1 >> player_2;
      if ((player_1 == "human" || player_1 == "computer[1]" || player_1 == "computer[2]" || player_1 == "computer[3]") &&
        (player_2 == "human" || player_2 == "computer[1]" || player_2 == "computer[2]" || player_2 == "computer[3]")) {
        string ai("computer");
        if (player_1.find(ai) != string::npos) {
          p1_human = false; // player computer
          char l = player_1.at(9);
          p1_level = l - '0';
        }
        if (player_2.find(ai) != string::npos) {
          p2_human = false; // player computer
          char l = player_2.at(9);
          p2_level = l - '0';
        }
        if (manual_setup == false) {
          not_custom_b = false;
          b.default_board();
          b.initialise_players(p1_human, p2_human, p1_level, p2_level);
        } else {
          cout << "Play your move." << endl;
          b.initialise_players(p1_human, p2_human, p1_level, p2_level);
        }

      } else {
        cout << "Invalid players." << endl;
      }
    } else if (command == "move") {
      char read_initial_col, read_final_col;
      int read_initial_row, read_final_row, initial_row, final_row, initial_col, final_col;
      cin >> read_initial_col >> read_initial_row >> read_final_col >> read_final_row;

      initial_col = get_col_int(read_initial_col);
      final_col = get_col_int(read_final_col);
      initial_row = read_initial_row - 1;
      final_row = read_final_row - 1;

      string piece;
      if (b.get_current_player().is_white() && (b.white_pawn_promotion(initial_col, initial_row, final_col, final_row))) {
          cin >> piece;
          b.replace_pawn(piece, final_col, final_row);     
      }
      if ((b.get_current_player().is_white() == false) && (b.black_pawn_promotion(initial_col, initial_row, final_col, final_row))) {
          cin >> piece;
          b.replace_pawn(piece, final_col, final_row);  
      }
      
      if (!(b.correct_command(read_initial_col, read_initial_row, read_final_col, read_final_row))) {
        cout << "Incorrect position" << endl;
      } else if (b.empty_square(initial_col, initial_row)) {
        cout << "This is an empty square. Not possible. " << endl;
      } else if (!b.correct_player(initial_col, initial_row)) {
        cout << "Not this player's turn" << endl;
      } else if (!(b.is_valid(initial_col, initial_row, final_col, final_row))) {
        cout << "Cannot move piece there" << endl;
      } else if (!(b.is_valid(initial_col, initial_row, final_col, final_row)) && b.becomes_check == true) {
        cout << "Cannot move King, will be in check" << endl;
      } else {
        b.update_board(initial_col, initial_row, final_col, final_row);

        if (b.is_check(initial_col, initial_row, final_col, final_row)) {
          if (b.is_checkmate(final_col, final_row)) {
            cout << "Checkmate, game over" << endl;
            return 0;
          } else {
            cout << "You are in check" << endl;
          }
        }
      }
    } else if (command == "resign") {
      if (b.get_current_player().is_white() == true) {
        score_b++;
      } else {
        score_w++;
      }
    } else if (command == "exit") {
      break;

    } else {
      cout << "Command not found." << endl;
    }
  }
  // scoreboard
  cout << "Final Score:" << endl;
  cout << "White:" << score_w << endl;
  cout << "Black:" << score_b << endl;
}