//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Rook.h"

Rook::Rook(std::string name, Color color) : Piece(name, color){}

Rook::~Rook() = default;

std::string Rook::getName() {
    std::string s;
    s+="\x1B[";
    if(this->getColor() == WHITE){
        s+= "37m";
    }
    else if(this->getColor() == BLACK){
        s+= "30m";
    }

    s+="R\033[0m";

    return s;
}