//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    Rook(Color);
    ~Rook();
    const std::string toString() const;
};


#endif //CHESS_ROOK_H
