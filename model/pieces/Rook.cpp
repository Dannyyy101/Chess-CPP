//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "Rook.h"

Rook::Rook(Color color) : Piece("Rook", color) {

}

Rook::~Rook() {}

const std::string Rook::toString() const {
    std::string s = "";
    if(this->getColor() == Color::WHITE){
        s+= "\x1B[37m";
    }else{
        s+= "\x1B[30m";
    }
     s += "R\033[0m";

    return s;
}