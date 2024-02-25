//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "Pawn.h"

Pawn::Pawn(const Color color) : Piece("Pawn", color){

}

Pawn::~Pawn() {}

const std::string Pawn::toString() const {
    std::string s = "";
    if(this->getColor() == Color::WHITE){
        s+= "\x1B[37m";
    }else{
        s+= "\x1B[30m";
    }
    s += "P\033[0m";

    return s;
}