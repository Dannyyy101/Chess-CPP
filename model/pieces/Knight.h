//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Piece.h"

class Knight : public Piece{
public:
    Knight(Color);
    ~Knight();
    const std::string toString() const;
};


#endif //CHESS_KNIGHT_H
