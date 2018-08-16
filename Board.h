//
// Created by benjamin on 8/12/18.
//

#ifndef CHESS_ENGINE_BOARD_H
#define CHESS_ENGINE_BOARD_H

#include <string>
#include <ostream>

using namespace std;

class Board {
private:
    bool whiteQueenCastled;
    bool whiteKingCastled;
    bool blackQueenCastled;
    bool blackKingCastled;
    int en_passant_row;
    int en_passant_file;
    char board[8][8];
    bool current_player;
    int halfmove;
    int fullmove;

public:
    Board();
    Board(string fen);

    friend ostream& operator<<(ostream& os, const Board& dt);





};


#endif //CHESS_ENGINE_BOARD_H
