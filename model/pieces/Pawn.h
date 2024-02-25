//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Piece.h"

class Pawn : public Piece{

public:
    Pawn(const Color);
    ~Pawn();
    const std::string toString() const;
};

#endif //CHESS_PAWN_H
