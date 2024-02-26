//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Pawn.h"

Pawn::Pawn(std::string name, Color color) : Piece(name, color){}

Pawn::~Pawn() = default;

std::string Pawn::getName() {
    std::string s;
    s+="\x1B[";
    if(this->getColor() == WHITE){
        s+= "37m";
    }
    else if(this->getColor() == BLACK){
        s+= "30m";
    }

    s+="P\033[0m";

    return s;
}