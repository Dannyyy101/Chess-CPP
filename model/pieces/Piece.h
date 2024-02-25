//
// Created by Daniel Stöcklein on 21.02.24.
//


#include "../../core/Color.h"
#include "../../core/Position.h"


#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include "../Field.h"

class Piece {
private:
    std::string name_;
    Field field_;
    Color color_;
public:
    void isPossibleToMoveTo(Position position_);
    void moveTo(Position position_);
    std::string getName();
    Field getField();
};


#endif //PIECE_H
