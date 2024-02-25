//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H


#include "Piece.h"

class Queen : public Piece{
public:
    Queen(Color);
    ~Queen();
    const std::string toString() const;
};


#endif //CHESS_QUEEN_H
