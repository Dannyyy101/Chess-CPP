//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include <iostream>
#include <string>

#include "Piece.h"
#include "core/include/Color.h"

class Bishop : public Piece{
public:
    Bishop(std::string name, Color color, Position* position, Board* board);
    ~Bishop();
    bool isMoveAllowed(Position position);
    std::string getName();
};


#endif //CHESS_BISHOP_H
