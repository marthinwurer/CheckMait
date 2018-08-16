//
// Created by benjamin on 8/12/18.
//

#include "Board.h"

Board::Board() {

}

Board::Board(string fen) {


}

ostream &operator<<(ostream &os, const Board &board) {
    return os << "Board at " << &board;
}
