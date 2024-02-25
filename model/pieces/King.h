//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Piece.h"

class King : public Piece{
public:
    King(Color);
    ~King();
    const std::string toString() const;
};


#endif //CHESS_KING_H
