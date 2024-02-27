//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <iostream>
#include <string>

#include "Piece.h"
#include "core/include/Color.h"

class Pawn : public Piece{
private:
    bool isMoved;
public:
    Pawn(std::string name, Color color, Position* position, Board* board);
    ~Pawn();
    bool isMoveAllowed(Position position);
    bool whiteMove(Position position);
    bool blackMove(Position position);
    std::string getName();
};


#endif //CHESS_PAWN_H
