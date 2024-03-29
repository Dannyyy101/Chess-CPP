//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <iostream>
#include <string>

#include "Piece.h"
#include "core/include/Color.h"

class King : public Piece{
public:
    King(std::string name, Color color, Position* position, Board* board);
    ~King();
    bool isMoveAllowed(Position position);
    std::string getName();
};


#endif //CHESS_KING_H
