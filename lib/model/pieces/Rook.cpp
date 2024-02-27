//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/pieces/Rook.h"

Rook::Rook(std::string name, Color color, Position* position, Board* board) : Piece(name, color, position, board){}

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

bool Rook::isMoveAllowed(Position position) {
    return false;
}