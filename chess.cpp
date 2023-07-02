#include "chess.h"

std::string chessboard[8][8] = {
        {"RKB", "KNB", "BWB", "QNB", "KGB", "BBB", "KNB", "RKB"},
        {"PWB", "PWB", "PWB", "PWB", "PWB", "PWB", "PWB", "PWB"},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"", "", "", "", "", "", "", ""},
        {"PWW", "PWW", "PWW", "PWW", "PWW", "PWW", "PWW", "PWW"},
        {"RKW", "KNW", "BWW", "QNW", "KGW", "BBW", "KNW", "RKW"},
};

bool isOppenent(char myColor, int x, int y) {
    return chessboard[y][x][2] != myColor;
}

bool isVoidCase(int x, int y) {
    return chessboard[y][x].length() <= 0;
}

std::list<Coordinate> pawnMovePossible(int x, int y, char color) {
    std::list<Coordinate> moves;
    if(color == WHITE) {
        if(isVoidCase(x, y-1)) {
            moves.push_back(Coordinate{x, y-1});
        }
        if(isVoidCase(x, y-2) && y == 6 && isVoidCase(x, y-1)) {
            moves.push_back(Coordinate{x, y-2});
        }
        if(!isVoidCase(x+1, y-1) && isOppenent(color, x+1, y-1)) {
            moves.push_back(Coordinate{x+1, y-1});
        }
        if(!isVoidCase(x-1, y-1) && isOppenent(color, x-1, y-1)) {
            moves.push_back(Coordinate{x-1, y-1});
        }
    } else if(color == BLACK) {
        if(isVoidCase(x, y+1)) {
            moves.push_back(Coordinate{x, y+1});
        }
        if(isVoidCase(x, y+2) && y == 1 && isVoidCase(x, y+1)) {
            moves.push_back(Coordinate{x, y+2});
        }
        if(!isVoidCase(x+1, y+1) && isOppenent(color, x+1, y+1)) {
            moves.push_back(Coordinate{x+1, y+1});
        }
        if(!isVoidCase(x-1, y+1) && isOppenent(color, x-1, y+1)) {
            moves.push_back(Coordinate{x-1, y+1});
        }
    }
    return moves;
}

std::list<Coordinate> rockMovePossible(int x, int y, char color) {
    std::list<Coordinate> moves;
    // Horizontal
    for(int i = x+1; i < 8; i++) {
        if(isVoidCase(i, y)) {
            moves.push_back(Coordinate{i, y});
        } else if (isOppenent(color, i, y)) {
            moves.push_back(Coordinate{i, y});
            break;
        } else {
            break;
        }
    }
    for(int i = x-1; i >= 0; i--) {
        if(isVoidCase(i, y)) {
            moves.push_back(Coordinate{i, y});
        } else if (isOppenent(color, i, y)) {
            moves.push_back(Coordinate{i, y});
            break;
        } else {
            break;
        }
    }

    // Vertical
    for(int i = y+1; i < 8; i++) {
        if(isVoidCase(x, i)) {
            moves.push_back(Coordinate{x, i});
        } else if (isOppenent(color, x, i)) {
            moves.push_back(Coordinate{x, i});
            break;
        } else {
            break;
        }
    }
    for(int i = y-1; i >= 0; i--) {
        if(isVoidCase(x, i)) {
            moves.push_back(Coordinate{x, i});
        } else if (isOppenent(color, x, i)) {
            moves.push_back(Coordinate{x, i});
            break;
        } else {
            break;
        }
    }
    return moves;
}
