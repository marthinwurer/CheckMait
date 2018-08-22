#include <iostream>
#include "Board.h"

int main() {
    Board board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    std::cout << endl << "Hello, World!" << std::endl << endl;
    Board kiwipete("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - ");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}