//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include <iostream>
#include <string>

#include "Piece.h"
#include "core/Color.h"

class Rook : public Piece{
public:
    Rook(std::string name, Color color, Position* position, Board* board);
    ~Rook();
    bool isMoveAllowed(Position position);
    std::string getName();
};


#endif //CHESS_ROOK_H
