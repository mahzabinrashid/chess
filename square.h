class Square {
    int row;
	int col;
    Board *chess_board;
    Piece *chess_piece;

    public:
    int get_row();
	int get_col();
    Piece *get_piece();
    void set_piece(piece* chess_piece);
    void make_empty();
};