//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "King.h"

King::King(std::string name, Color color) : Piece(name, color){}

King::~King() = default;

std::string King::getName() {
    std::string s;
    s+="\x1B[";
    if(this->getColor() == WHITE){
        s+= "37m";
    }
    else if(this->getColor() == BLACK){
        s+= "30m";
    }

    s+="K\033[0m";

    return s;
}