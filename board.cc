#include <iostream>
#include "board.h"
#include "square.h"
#include "piece.h"
#include <vector>

using namespace std;

// helper functions
string board_coordinates(int col, int row) {
  string horizontal;
  string vertical;
  if (col == 0) horizontal = "a";
  if (col == 1) horizontal = "b";
  if (col == 2) horizontal = "c";
  if (col == 3) horizontal = "d";
  if (col == 4) horizontal = "e";
  if (col == 5) horizontal = "f";
  if (col == 6) horizontal = "g";
  if (col == 7) horizontal = "h";
  if (row == 0) vertical = "1";
  if (row == 1) vertical = "2";
  if (row == 2) vertical = "3";
  if (row == 3) vertical = "4";
  if (row == 4) vertical = "5";
  if (row == 5) vertical = "6";
  if (row == 6) vertical = "7";
  if (row == 7) vertical = "8";
  return horizontal + vertical;
}

// move this func to addtext
void print(vector <vector<Square>> board) {
  string name;
  for (std::size_t i = board.size(); i > 0; --i) {
    for (std::size_t j = 0; j < board[i - 1].size(); ++j) {
      name = board[i - 1][j].get_piece() -> get_name();
      if (name == "empty") {
        if (board[i - 1][j].get_piece() -> is_white() == true) {
          cout << " ";
        } else {
          cout << "-";
        }
      } else {
        cout << name;
      }
    }
    cout << endl;
  }
}

// methods
// allocates memory for the empty board
void Board::empty_board() {
  for (int i = 0; i < 8; i++) {
    vector < Square > k;
    for (int j = 0; j < 8; j++) {
      if ((i + j) % 2 == 0) {
        k.emplace_back(Square(i, j, new Piece("empty", false)));
      } else {
        k.emplace_back(Square(i, j, new Piece("empty", true)));
      }
    }
    board.emplace_back(k);
  }
}

// initialising the 2 players
void Board::initialise_players(bool p1_human, bool p2_human, int p1_level, int p2_level) {
  players.emplace_back(Player(true, p1_human, p1_level));
  players.emplace_back(Player(false, p2_human, p2_level));
  current_player = players[0];
}

void Board::update_board(int col_i, int row_i, int col_f, int row_f) {
  delete board[row_f][col_f].get_piece();
  board[row_f][col_f].set_piece(board[row_i][col_i].get_piece());
  if ((row_i + col_i) % 2 == 0) {
    board[row_i][col_i].set_piece(new Piece("empty", false));
  } else {
    board[row_i][col_i].set_piece(new Piece("empty", true));
  }
  if (current_player.is_white() == players[0].is_white()) {
    current_player = players[1];
  } else {
    current_player = players[0];
  }
  print(board);
}

// setup methods
void Board::put_piece(string piece, int final_col, int final_row) {
  bool wp;
  if (isupper(piece[0])) {
    wp = true;
  } else {
    wp = false;
  }
  delete board[final_row][final_col].get_piece();
  board[final_row][final_col] = Square(final_row, final_col, new Piece(piece, wp));
  print(board);
}

void Board::delete_piece(int col_f, int row_f) {
  delete board[row_f][col_f].get_piece();
  if ((row_f + col_f) % 2 == 0) {
    board[row_f][col_f].set_piece(new Piece("empty", false));
  } else {
    board[row_f][col_f].set_piece(new Piece("empty", true));
  }
  print(board);
}

void Board::change_current_player(bool white) {
    current_player.set_white(white);
}

void Board::setup_board() {
  empty_board();
  // initialising the 2 players
  players.emplace_back(Player(true, true, 0));
  players.emplace_back(Player(false, true, 0));
  current_player = players[0];
  print(board);
}

bool Board::valid_setup() {
  // ALSO neither king is in check! (not implemented)
  bool valid;
  int wk = 0;
  int bk = 0;
  // board contains exactly one white king and exactly one black king
  for (std::size_t i = board.size(); i > 0; --i) {
    for (std::size_t j = 0; j < board[i - 1].size(); ++j) {
      if (board[i - 1][j].get_piece() -> get_name() == "K") {
        wk++;
      }
      if (board[i - 1][j].get_piece() -> get_name() == "k") {
        bk++;
      }
    }
  }
  if ((wk == 1) && (bk == 1)) {
    valid = true;
  } else {
    valid = false;
  }
  // no pawns are on the first or last row of the board
  for (int i = 0; i < 8; i++) {
    if ((board[7][i].get_piece() -> get_name() == "p") || (board[0][i].get_piece() -> get_name() == "p") ||
      (board[7][i].get_piece() -> get_name() == "P") || (board[0][i].get_piece() -> get_name() == "P")) {
      valid = false;
    }
  }
  return valid;
}

// default game methods
void Board::default_board() {
  // creates the initial checkerboard
  empty_board();
  for (int i = 0; i < 8; i++) {
    delete board[7][i].get_piece();
    delete board[0][i].get_piece();
    delete board[6][i].get_piece();
    delete board[1][i].get_piece();
  }
  // fills checkerboard with pieces
  board[7][0] = Square(7, 0, new Piece("r", false));
  board[7][1] = Square(7, 1, new Piece("n", false));
  board[7][2] = Square(7, 2, new Piece("b", false));
  board[7][3] = Square(7, 3, new Piece("q", false));
  board[7][4] = Square(7, 4, new Piece("k", false));
  board[7][5] = Square(7, 5, new Piece("b", false));
  board[7][6] = Square(7, 6, new Piece("n", false));
  board[7][7] = Square(7, 7, new Piece("r", false));

  board[0][0] = Square(0, 0, new Piece("R", true));
  board[0][1] = Square(0, 1, new Piece("N", true));
  board[0][2] = Square(0, 2, new Piece("B", true));
  board[0][3] = Square(0, 3, new Piece("Q", true));
  board[0][4] = Square(0, 4, new Piece("K", true));
  board[0][5] = Square(0, 5, new Piece("B", true));
  board[0][6] = Square(0, 6, new Piece("N", true));
  board[0][7] = Square(0, 7, new Piece("R", true));

  for (int i = 0; i < 8; i++) {
    board[6][i] = Square(6, i, new Piece("p", false));
  }
  for (int i = 0; i < 8; i++) {
    board[1][i] = Square(6, i, new Piece("P", true));
  }
  print(board);
}

// getters and settors
Player Board::get_current_player() {
  return current_player;
}

void Board::set_current_player(bool white) {
  current_player.set_white(white);
}


// valid moves
vector < string > Board::valid_moves(string name, int col_i, int row_i, int col_f, int row_f) {
  b_pawn_promotion = false;
  w_pawn_promotion = false;
  vector < string > moves;
  // white pawn
  if (name == "P") {
    // checks if pawn can move forward
    if (row_i != 7 && board[row_i + 1][col_i].get_piece() -> get_name() == "empty") {
      moves.emplace_back(board_coordinates(col_i, row_i + 1));
      if (row_i == 6) {
        w_pawn_promotion = true;
      }
    }
    // checks if pawn can move forward two steps from the starting position
    if (row_i == 1 && board[row_i + 2][col_i].get_piece() -> get_name() == "empty") {
      moves.emplace_back(board_coordinates(col_i, row_i + 2));
    }
    // capturing using pawn
    if (col_i != 7) {
      if (!(board[row_i + 1][col_i + 1].get_piece() -> get_name() == "empty") && board[row_i + 1][col_i + 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i + 1));
      }
    }
    if (col_i != 0) {
      if (!(board[row_i + 1][col_i - 1].get_piece() -> get_name() == "empty") && board[row_i + 1][col_i - 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i + 1));
      }
    }
  }
  // black pawn
  if (name == "p") {
    // checks if pawn can move forward
    if (row_i != 0 && board[row_i - 1][col_i].get_piece() -> get_name() == "empty") {
      moves.emplace_back(board_coordinates(col_i, row_i - 1));
      if (row_i == 1) {
        b_pawn_promotion = true;
      }
    }
    // checks if pawn can move forward two steps from the starting position
    if (row_i == 6 && board[row_i - 2][col_i].get_piece() -> get_name() == "empty") {
      moves.emplace_back(board_coordinates(col_i, row_i - 2));
    }
    // capturing using pawn
    if (col_i != 7) {
      if (!(board[row_i - 1][col_i + 1].get_piece() -> get_name() == "empty") && board[row_i - 1][col_i + 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i - 1));
      }
    }
    if (col_i != 0) {
      if (!(board[row_i - 1][col_i - 1].get_piece() -> get_name() == "empty") && board[row_i - 1][col_i - 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i - 1));
      }
    }
  }
  // white knight
  if (name == "N") {
    // moves (x+1),(y+2)
    if (row_i + 2 < 8 && col_i != 7) {
      if (board[row_i + 2][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i + 2][col_i + 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i + 2));
      }
    }
    // moves (x-1),(y+2)
    if (row_i + 2 < 8 && col_i != 0) {
      if (board[row_i + 2][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i + 2][col_i - 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i + 2));
      }
    }
    // moves (x+2),(y+1)
    if (row_i != 7 && col_i + 2 < 8) {
      if (board[row_i + 1][col_i + 2].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i + 2].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 2, row_i + 1));
      }
    }
    // moves (x-2),(y+1)
    if (row_i != 7 && col_i - 2 >= 0) {
      if (board[row_i + 1][col_i - 2].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i - 2].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 2, row_i + 1));
      }
    }
    // moves (x+1),(y-2)
    if (row_i - 2 >= 0 && col_i != 7) {
      if (board[row_i - 2][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i - 2][col_i + 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i - 2));
      }
    }
    // moves (x-1),(y-2)
    if (row_i - 2 >= 0 && col_i != 0) {
      if (board[row_i - 2][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i - 2][col_i - 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i - 2));
      }
    }
    // moves (x+2),(y-1)
    if (row_i != 0 && col_i + 2 < 8) {
      if (board[row_i - 1][col_i + 2].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i + 2].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 2, row_i - 1));
      }
    }
    // moves (x-2),(y-1)
    if (row_i != 0 && col_i - 2 >= 0) {
      if (board[row_i - 1][col_i - 2].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i - 2].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 2, row_i - 1));
      }
    }
  }
  // black knight
  if (name == "n") {
    // moves (x+1),(y+2)
    if (row_i + 2 < 8 && col_i != 7) {
      if (board[row_i + 2][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i + 2][col_i + 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i + 2));
      }
    }
    // moves (x-1),(y+2)
    if (row_i + 2 < 8 && col_i != 0) {
      if (board[row_i + 2][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i + 2][col_i - 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i + 2));
      }
    }
    // moves (x+2),(y+1)
    if (row_i != 7 && col_i + 2 < 8) {
      if (board[row_i + 1][col_i + 2].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i + 2].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 2, row_i + 1));
      }
    }
    // moves (x-2),(y+1)
    if (row_i != 7 && col_i - 2 >= 0) {
      if (board[row_i + 1][col_i - 2].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i - 2].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 2, row_i + 1));
      }
    }
    // moves (x+1),(y-2)
    if (row_i - 2 >= 0 && col_i != 7) {
      if (board[row_i - 2][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i - 2][col_i + 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i - 2));
      }
    }
    // moves (x-1),(y-2)
    if (row_i - 2 >= 0 && col_i != 0) {
      if (board[row_i - 2][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i - 2][col_i - 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i - 2));
      }
    }
    // moves (x+2),(y-1)
    if (row_i != 0 && col_i + 2 < 8) {
      if (board[row_i - 1][col_i + 2].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i + 2].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 2, row_i - 1));
      }
    }
    // moves (x-2),(y-1)
    if (row_i != 0 && col_i - 2 >= 0) {
      if (board[row_i - 1][col_i - 2].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i - 2].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 2, row_i - 1));
      }
    }
  }
  // white rook
  if (name == "R") {
    // checks movements vertically upwards
    for (int i = row_i + 1; i < 8; ++i) {
      if (board[i][col_i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(col_i, i));
      } else if (board[i][col_i].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i, i));
        break;
      } else {
        break;
      }
    }
    // checks movements vertically downwards
    for (int i = row_i - 1; i >= 0; --i) {
      if (board[i][col_i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(col_i, i));
      } else if (board[i][col_i].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i, i));
        break;
      } else {
        break;
      }
    }
    // checks movements rightwards
    for (int i = col_i + 1; i < 8; ++i) {
      if (board[row_i][i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(i, row_i));
      } else if (board[row_i][i].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(i, row_i));
        break;
      } else {
        break;
      }
    }
    // checks movements leftwards
    for (int i = col_i - 1; i >= 0; --i) {
      if (board[row_i][i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(i, row_i));
      } else if (board[row_i][i].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(i, row_i));
        break;
      } else {
        break;
      }
    }
  }
  // black rook
  if (name == "r") {
    // checks movements vertically upwards
    for (int i = row_i + 1; i < 8; ++i) {
      if (board[i][col_i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(col_i, i));
      } else if (board[i][col_i].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i, i));
        break;
      } else {
        break;
      }
    }
    // checks movements vertically downwards
    for (int i = row_i - 1; i >= 0; --i) {
      if (board[i][col_i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(col_i, i));
      } else if (board[i][col_i].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i, i));
        break;
      } else {
        break;
      }
    }
    // checks movements rightwards
    for (int i = col_i + 1; i < 8; ++i) {
      if (board[row_i][i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(i, row_i));
      } else if (board[row_i][i].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(i, row_i));
        break;
      } else {
        break;
      }
    }
    // checks movements leftwards
    for (int i = col_i - 1; i >= 0; --i) {
      if (board[row_i][i].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(i, row_i));
      } else if (board[row_i][i].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(i, row_i));
        break;
      } else {
        break;
      }
    }
  }
  // white bishop
  if (name == "B") {
    // checks movements diagonally to the right and upwards
    for (int i = row_i + 1, j = col_i + 1; i < 8 && j < 8; ++i, ++j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
    // checks movements diagonally to the left and upwards
    for (int i = row_i + 1, j = col_i - 1; i < 8 && j >= 0; ++i, --j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
    // checks movements diagonally downwards and rightwards
    for (int i = row_i - 1, j = col_i + 1; i >= 0 && j < 8; --i, ++j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
    // checks movements diagonally downwards and leftwards
    for (int i = row_i - 1, j = col_i - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
  }
  // black bishop
  if (name == "b") {
    // checks movements diagonally to the right and upwards
    for (int i = row_i + 1, j = col_i + 1; i < 8 && j < 8; ++i, ++j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
    // checks movements diagonally to the left and upwards
    for (int i = row_i + 1, j = col_i - 1; i < 8 && j >= 0; ++i, --j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
    // checks movements diagonally downwards and rightwards
    for (int i = row_i - 1, j = col_i + 1; i >= 0 && j < 8; --i, ++j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
    // checks movements diagonally downwards and leftwards
    for (int i = row_i - 1, j = col_i - 1; i >= 0 && j >= 0; --i, --j) {
      if (board[i][j].get_piece() -> get_name() == "empty") {
        moves.emplace_back(board_coordinates(j, i));
      } else if (board[i][j].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(j, i));
        break;
      } else {
        break;
      }
    }
  }
  // white queen
  if (name == "Q") {
    vector < string > queen_r = valid_moves("R", col_i, row_i, col_f, row_f);
    vector < string > queen_b = valid_moves("B", col_i, row_i, col_f, row_f);
    for (int i = 0; i < queen_r.size(); ++i) {
      moves.emplace_back(queen_r[i]);
    }
    for (std::size_t i = 0; i < queen_b.size(); ++i) {
      moves.emplace_back(queen_b[i]);
    }
  }
  // black queen
  if (name == "q") {
    vector < string > queen_r = valid_moves("r", col_i, row_i, col_f, row_f);
    vector < string > queen_b = valid_moves("b", col_i, row_i, col_f, row_f);
    for (int i = 0; i < queen_r.size(); ++i) {
      moves.emplace_back(queen_r[i]);
    }
    for (std::size_t i = 0; i < queen_b.size(); ++i) {
      moves.emplace_back(queen_b[i]);
    }
  }
  // white king
  if (name == "K") {
    // moves forward
    if (row_i != 7) {
      if (board[row_i + 1][col_i].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i, row_i + 1));
      }
    }
    // moves backward
    if (row_i != 0) {
      if (board[row_i - 1][col_i].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i, row_i - 1));
      }
    }
    // moves rightward
    if (col_i != 7) {
      if (board[row_i][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i][col_i + 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i));
      }
    }
    // moves leftward
    if (col_i != 0) {
      if (board[row_i][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i][col_i - 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i));
      }
    }
    // moves diagonally up and right
    if (row_i != 7 and col_i != 7) {
      if (board[row_i + 1][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i + 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i + 1));
      }
    }
    // moves diagonally down and left
    if (row_i != 0 && col_i != 0) {
      if (board[row_i - 1][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i - 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i - 1));
      }
    }
    // moves diagonally up and left
    if (row_i != 7 && col_i != 0) {
      if (board[row_i + 1][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i - 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i + 1));
      }
    }
    // moves diagonally down and right
    if (row_i != 0 && col_i != 7) {
      if (board[row_i - 1][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i + 1].get_piece() -> is_white() == false) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i - 1));
      }
    }
  }
  // black king
  if (name == "k") {
    // moves forward
    if (row_i != 7) {
      if (board[row_i + 1][col_i].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i, row_i + 1));
      }
    }
    // moves backward
    if (row_i != 0) {
      if (board[row_i - 1][col_i].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i, row_i - 1));
      }
    }
    // moves rightward
    if (col_i != 7) {
      if (board[row_i][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i][col_i + 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i));
      }
    }
    // moves leftward
    if (col_i != 0) {
      if (board[row_i][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i][col_i - 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i));
      }
    }
    // moves diagonally up and right
    if (row_i != 7 and col_i != 7) {
      if (board[row_i + 1][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i + 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i + 1));
      }
    }
    // moves diagonally down and left
    if (row_i != 0 && col_i != 0) {
      if (board[row_i - 1][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i - 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i - 1));
      }
    }
    // moves diagonally up and left
    if (row_i != 7 && col_i != 0) {
      if (board[row_i + 1][col_i - 1].get_piece() -> get_name() == "empty" || board[row_i + 1][col_i - 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i - 1, row_i + 1));
      }
    }
    // moves diagonally down and right
    if (row_i != 0 && col_i != 7) {
      if (board[row_i - 1][col_i + 1].get_piece() -> get_name() == "empty" || board[row_i - 1][col_i + 1].get_piece() -> is_white() == true) {
        moves.emplace_back(board_coordinates(col_i + 1, row_i - 1));
      }
    }
  }
  return moves;
}

bool Board::is_valid(int col_i, int row_i, int col_f, int row_f) {
  becomes_check = false;
  string object = board[row_i][col_i].get_piece() -> get_name();
  string notation_f = board_coordinates(col_f, row_f);
  vector < string > possible_moves = valid_moves(object, col_i, row_i, col_f, row_f);
  if (object != "k" && object != "K") {
    for (int i = 0; i < possible_moves.size(); ++i) {
      if (notation_f == possible_moves[i]) {
        return true;
      }
    }
  } else {
    for (std::size_t i = 0; i < possible_moves.size(); ++i) {
      if (notation_f == possible_moves[i]) {
        bool white = board[row_i][col_i].get_piece() -> is_white();
        if (!(will_be_check(object, white, notation_f))) {
          return true;
        } else {
          becomes_check = true;
        }
      }
    }
  }
  return false;
}

// checks if input is correct
bool Board::correct_command(char col_i, int row_i, char col_f, int row_f) {
  if (row_i < 1 || row_i > 8 || row_f < 1 || row_f > 8) {
    return false;
  }
  if (col_i < 'a' || col_i > 'h' || col_f < 'a' || col_f > 'h') {
    return false;
  }
  return true;
}

bool Board::correct_player(int col_i, int row_i) {
  if (current_player.is_white() == board[row_i][col_i].get_piece() -> is_white()) {
    return true;
  } else {
    return false;
  }
}

bool Board::empty_square(int initial_col, int initial_row) {
  if (board[initial_row][initial_col].get_piece() -> get_name() == "empty") {
    return true;
  } else {
    return false;
  }
}

// check
// so far sees if there is a check after a piece has been moves by the opponent
/*bool Board::is_check(int col_i, int row_i, int col_f, int row_f) {
  string object = board[row_f][col_f].get_piece() -> get_name();
  vector < string > possible_moves = valid_moves(object, col_f, row_f, col_i, row_i);
  bool white = board[row_f][col_f].get_piece() -> is_white();
  string king;
  if (white == true) {
    king = "k";
  } else {
    king = "K";
  }
  int king_row;
  int king_col;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; j++) {
      string temp = board[i][j].get_piece() -> get_name();
      if (temp == king) {
        king_row = i;
        king_col = j;
        break;
      }
    }
  }
  string king_pos = board_coordinates(king_col, king_row);
  for (int i = 0; i < possible_moves.size(); ++i) {
    if (king_pos == possible_moves[i]) {
      return true;
    }
  }
  return false;
}*/
bool Board::is_check(bool white) {
    string king_pos;
    string king;
    vector <string> all_moves;
    if (white == true) {
        king = "K";
    } else {
        king = "k";
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].get_piece()->get_name() == king) {
                king_pos = board_coordinates(j,i);
            } else if (board[i][j].get_piece()->is_white() != white) {
                string temp = board[i][j].get_piece()->get_name();
                vector <string> temp_moves = valid_moves(temp, j, i, j, i);
                for (int k = 0; k < temp_moves.size(); k++) {
                    all_moves.emplace_back(temp_moves[k]);
                }
            }
        }
    }
    for (int i = 0; i < all_moves.size(); i++) {
        if (king_pos == all_moves[i]) {
            return true;
        }
    }
    return false;
}

// will be king's initial and final position
bool Board::will_be_check(string name, bool white, string final_pos) {
  vector < string > opponent_moves;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (board[i][j].get_piece() -> is_white() != white) {
        string temp_name = board[i][j].get_piece() -> get_name();
        vector < string > temp = valid_moves(temp_name, j, i, j, i);
        for (int k = 0; k < temp.size(); ++k) {
          opponent_moves.emplace_back(temp[k]);
        }
      }
    }
  }
  for (int i = 0; i < opponent_moves.size(); ++i) {
    if (final_pos == opponent_moves[i]) {
      return true;
    }
  }
  return false;
}

// checkmate
// requires the final position of the piece moved
bool Board::is_checkmate(int col, int row) {
  bool white = board[row][col].get_piece() -> is_white();
  string name;
  if (white == true) {
    name = "k";
  } else {
    name = "K";
  }
  bool color;
  if (name == "k") {
    color = false;
  } else {
    color = true;
  }
  int king_row;
  int king_col;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j].get_piece() -> get_name() == name) {
        king_row = i;
        king_col = j;
        break;
      }
    }
  }
  vector < string > possible_moves = valid_moves(name, king_col, king_row, king_col, king_row);
  int count = possible_moves.size();
  for (int i = 0; i < count; i++) {
    if (will_be_check(name, color, possible_moves[i])) {
      count--;
    }
  }
  if (count == 0) {
    return true;
  } else {
    return false;
  }
}

bool Board::is_stalemate(bool white) {
    if (white == true) {
        vector < string > all_moves;
        vector < string > king_moves;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j].get_piece() -> is_white() == true && board[i][j].get_piece() -> get_name() != "empty") {
                    string temp_name = board[i][j].get_piece() -> get_name();
                    if (temp_name == "K") {
                        vector < string > temp = valid_moves(temp_name, j, i, j, i);
                        for (int k = 0; k < temp.size(); k++) {
                            king_moves.emplace_back(temp[k]);
                        }
                    } else {
                        vector < string > temp = valid_moves(temp_name, j, i, j, i);
                        for (int k = 0; k < temp.size(); ++k) {
                            all_moves.emplace_back(temp[k]);                          
                        }
                    }
                }
            }
        }
        int count = 0;
        if (all_moves.size() == 0) {
            for (int i = 0; i < king_moves.size(); i++) {
                if (!(will_be_check("K", true, king_moves[i]))) {
                    count++;
                }
            }
        } else {
            count++;
        }
        if (count == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        vector < string > all_moves;
        vector < string > king_moves;
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j].get_piece() -> is_white() == false && board[i][j].get_piece() -> get_name() != "empty") {
                    string temp_name = board[i][j].get_piece() -> get_name();
                    if (temp_name == "k") {
                        vector < string > temp = valid_moves(temp_name, j, i, j, i);
                        for (int k = 0; k < temp.size(); k++) {
                            king_moves.emplace_back(temp[k]);
                        }
                    } else {
                        vector < string > temp = valid_moves(temp_name, j, i, j, i);
                        for (int k = 0; k < temp.size(); ++k) {
                            all_moves.emplace_back(temp[k]);
                        }
                    }
                }
            }
        }
        int count = 0;
        if (all_moves.size() == 0) {
            for (int i = 0; i < king_moves.size(); i++) {
                if (!(will_be_check("k", false, king_moves[i]))) {
                    count++;
                }
            }
        } else {
          count++;
        }
        if (count == 0) {
            return true;
        } else {
            return false;
        }
    }
}
// pawn promotion
bool Board::white_pawn_promotion(int col_i, int row_i) {
    if (row_i == 6) {
        if (board[row_i][col_i].get_piece()->get_name() == "P") {
            return true;
        }
    }
    return false;
}

bool Board::black_pawn_promotion(int col_i, int row_i) {
    if (row_i == 1) {
        if (board[row_i][col_i].get_piece()->get_name() == "p") {
           return true;
        }
    }
    return false;
}

void Board::replace_pawn(string piece, bool white,int col_f, int row_f) {
    delete board[row_f][col_f].get_piece();
    board[row_f][col_f] = Square(row_f, col_f, new Piece(piece, white));
}

// destructor
Board::~Board() {
  for (std::size_t i = board.size(); i > 0; --i) {
    for (std::size_t j = 0; j < board[i - 1].size(); ++j) {
      delete board[i - 1][j].get_piece();
    }
  }
}