//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include <iostream>
#include <string>

#include "Piece.h"
#include "core/Color.h"

class Knight : public Piece{
public:
    Knight(std::string name, Color color, Position* position, Board* board);
    ~Knight();
    bool isMoveAllowed(Position position);
    std::string getName();
};


#endif //CHESS_KNIGHT_H
