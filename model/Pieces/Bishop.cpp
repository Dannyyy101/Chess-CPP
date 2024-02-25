//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Bishop.h"

Bishop::Bishop(std::string name, Color color) : Piece(name, color){}

Bishop::~Bishop() = default;

std::string Bishop::getName() {
    std::string s;
    s+="\x1B[";
    if(this->getColor() == WHITE){
        s+= "37m";
    }
    else if(this->getColor() == BLACK){
        s+= "30m";
    }

    s+="B\033[0m";

    return s;
}