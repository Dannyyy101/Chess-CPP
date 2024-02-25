//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "Knight.h"

Knight::Knight(Color color) : Piece("Knight", color) {}

Knight::~Knight() {}

const std::string Knight::toString() const {
    std::string s = "";
    if(this->getColor() == Color::WHITE){
        s+= "\x1B[37m";
    }else{
        s+= "\x1B[30m";
    }
    s += "k\033[0m";

    return s;
}