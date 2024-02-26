//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include <iostream>
#include <string>

#include "Piece.h"
#include "core/Color.h"

class Pawn : public Piece{
public:
    Pawn(std::string name, Color color);
    ~Pawn();
    std::string getName();
};


#endif //CHESS_PAWN_H
