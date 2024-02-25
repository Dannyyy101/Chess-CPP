//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "Bishop.h"

Bishop::Bishop(Color color) : Piece("Bishop", color){}

Bishop::~Bishop() {}

const std::string Bishop::toString() const {
    std::string s = "";
    if(this->getColor() == Color::WHITE){
        s+= "\x1B[37m";
    }else{
        s+= "\x1B[30m";
    }
    s += "B\033[0m";

    return s;
}