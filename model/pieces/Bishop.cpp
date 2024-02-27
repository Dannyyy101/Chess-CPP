//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Bishop.h"

Bishop::Bishop(std::string name, Color color, Position* position, Board* board) : Piece(name, color, position, board){}

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

bool Bishop::isMoveAllowed(Position position) {
    return false;
}