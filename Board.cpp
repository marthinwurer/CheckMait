//
// Created by benjamin on 8/12/18.
//

#include <iostream>
#include "Board.h"
#include "Utils.h"

Board::Board() {

}

Board::Board(string fen) {

    auto sections = split(fen, ' ');

    cout << sections.size();
    for (auto sec : sections){
        cout << sec << endl;
    }


}

ostream &operator<<(ostream &os, const Board &board) {
    return os << "Board at " << &board;
}
