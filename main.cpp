#include <iostream>
#include "chess.h"

int main() {
    std::list<Coordinate> moves = queenMovePossible(3, 4, WHITE);
    for(Coordinate move : moves) {
        std::cout << move.x << ";" << move.y << std::endl;
    }
    moves.clear();
}
