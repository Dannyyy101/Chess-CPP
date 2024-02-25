//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "King.h"

King::King(Color color) : Piece("King", color){}

King::~King() {}

const std::string King::toString() const {
    std::string s = "";
    if(this->getColor() == Color::WHITE){
        s+= "\x1B[37m";
    }else{
        s+= "\x1B[30m";
    }
    s += "K\033[0m";

    return s;
}
