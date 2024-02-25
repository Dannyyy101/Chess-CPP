//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Knight.h"

Knight::Knight(std::string name, Color color) : Piece(name, color){}

Knight::~Knight() = default;

std::string Knight::getName() {
    std::string s;
    s+="\x1B[";
    if(this->getColor() == WHITE){
        s+= "37m";
    }
    else if(this->getColor() == BLACK){
        s+= "30m";
    }

    s+="k\033[0m";

    return s;
}