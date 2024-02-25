//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "Queen.h"

Queen::Queen(Color color) : Piece("Queen", color){}

Queen::~Queen() {}

const std::string Queen::toString() const {
    std::string s = "";
    if(this->getColor() == Color::WHITE){
        s+= "\x1B[37m";
    }else{
        s+= "\x1B[30m";
    }
    s += "Q\033[0m";

    return s;
}