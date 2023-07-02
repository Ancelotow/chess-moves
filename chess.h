#ifndef CHESS_H
#define CHESS_H

#include <cstdlib>
#include <string>
#include <list>

struct Coordinate {
    int x;
    int y;
};

// Colors
const char WHITE = 'W';
const char BLACK = 'B';

// Pieces
const char BISHOP_WHITE[2] = {'B', 'W'};
const char BISHOP_BLACK[2] = {'B', 'B'};
const char KING[2] = {'K', 'G'};
const char KNIGHT[2] = {'K', 'N'};
const char PAWN[2] = {'P', 'W'};
const char QUEEN[2] = {'Q', 'N'};
const char ROCK[2] = {'R', 'K'};

extern std::string chessboard[8][8];

bool isOppenent(char myColor, int x, int y);
bool isVoidCase(int x, int y);

std::list<Coordinate> pawnMovePossible(int x, int y, char color);
std::list<Coordinate> rockMovePossible(int x, int y, char color);
std::list<Coordinate> bishopMove(int x, int y, char color);

#endif
