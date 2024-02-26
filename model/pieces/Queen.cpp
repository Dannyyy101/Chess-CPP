//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Queen.h"

Queen::Queen(std::string name, Color color) : Piece(name, color){}

Queen::~Queen() = default;

std::string Queen::getName() {
    std::string s;
    s+="\x1B[";
    if(this->getColor() == WHITE){
        s+= "37m";
    }
    else if(this->getColor() == BLACK){
        s+= "30m";
    }

    s+="Q\033[0m";

    return s;
}