//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <iostream>
#include <string>

#include "../../core/Color.h"


class Piece {
private:
    const std::string name_;
    Color color_;
public:
    Piece(std::string name, Color color);
    virtual ~Piece();
    virtual std::string getName() = 0;
    Color getColor();
};

#endif //CHESS_PIECE_H