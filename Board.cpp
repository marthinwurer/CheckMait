//
// Created by benjamin on 8/12/18.
//

#include <iostream>
#include <sstream>
#include <cassert>
#include "Board.h"
#include "Utils.h"

string to_notation(int row, int col) {
    if (row == -1) {
        return "-";
    }
    return string({(char)(col + 'a'), (char)(8 - row + '0')});
}

Board::Board() {

}

Board::Board(string fen) {

    auto sections = split(fen, ' ');
    auto rows = split(sections[0], '/');

    // check the values
    if (6 != sections.size()) {
        throw invalid_argument("Incorrect number of sections");
    }
    if (8 != rows.size()) {
        throw invalid_argument("Incorrect number of rows");
    }

//    cout << sections.size();
//    for (const auto &sec : sections){
//        cout << sec << endl;
//    }
//    cout << endl;
//    for (const auto &row : rows){
//        cout << row << endl;
//    }
//    cout << endl;

    // parse the board
    for (int row = 0; row < 8; row++) {
        int col = 0;
        for (char c : rows[row]) {
//            cout << c;
            if (isdigit(c)) {
                int skip = c - '0';
                for (int ii = 0; ii < skip; ii++) {
                    board[row][col] = '.';
                    col++;
                }
            } else {
                // TODO check if it's a valid char
                board[row][col] = c;
                col++;
            }
        }
//        cout << endl;
    }

    // parse the active player
    current_player = 'w' == sections[1][0];

    // parse castling
    if(string::npos != sections[2].find('-')) {
        // there is no castling left
        whiteKingCanCastle = false;
        whiteQueenCanCastle = false;
        blackKingCanCastle = false;
        whiteQueenCanCastle = false;
    } else {
        whiteKingCanCastle  = string::npos != sections[2].find('K');
        whiteQueenCanCastle = string::npos != sections[2].find('Q');
        blackKingCanCastle  = string::npos != sections[2].find('k');
        blackQueenCanCastle = string::npos != sections[2].find('q');
    }

    // parse en passant
    if(string::npos != sections[3].find('-')) {
        en_passant_file = -1;
        en_passant_row = -1;
    } else {
        en_passant_file = sections[3][0] - 'a';
        en_passant_row  = 8 - (sections[3][1] - '0');
    }

    // parse halfmove
    halfmove = stoi(sections[4]);

    // parse fullmove
    fullmove = stoi(sections[5]);
}

ostream &operator<<(ostream &os, const Board &board) {
    ostringstream ss;

    if (board.current_player) {
        ss << "White";
    } else {
        ss << "Black";
    }
    ss << " to move" << endl;
    // display board
    for(int row = 0; row < 8; row++) {
        ss << (8 - row);
        for (int col = 0; col < 8; col++) {
            ss << ' ';
            ss << board.board[row][col];
        }
        ss << endl;
    }
    ss << ' ';
    for (int col = 0; col < 8; col++) {
        ss << ' ' <<  (char)('a' + col);
    }
    ss << endl;

    // castling
    ss << "Castling: ";
    if (!(board.can_castle())) {
        ss << '-';
    }
    if (board.whiteKingCanCastle) {
        ss << 'K';
    }
    if (board.whiteQueenCanCastle) {
        ss << 'Q';
    }
    if (board.blackKingCanCastle) {
        ss << 'k';
    }
    if (board.blackQueenCanCastle) {
        ss << 'q';
    }
    ss << endl;

    // en passant
    ss << "EP internal: " << board.en_passant_row << ", " << board.en_passant_file << endl;
    ss << "EP normal: " << to_notation(board.en_passant_row, board.en_passant_file) << endl;

    // move #s
    ss << "Move numbers: " << board.halfmove << ", " << board.fullmove << endl;

    ss << endl;
    return os << "Board at " << &board << endl << ss.str();
}

const bool Board::can_castle() const {
    return whiteKingCanCastle || whiteQueenCanCastle || blackKingCanCastle || blackQueenCanCastle;
}
