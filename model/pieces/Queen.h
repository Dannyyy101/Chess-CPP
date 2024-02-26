//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include <iostream>
#include <string>

#include "Piece.h"
#include "core/Color.h"

class Queen : public Piece{
public:
    Queen(std::string name, Color color);
    ~Queen();
    std::string getName();
};


#endif //CHESS_QUEEN_H
