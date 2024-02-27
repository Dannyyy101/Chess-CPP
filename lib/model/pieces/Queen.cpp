//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/pieces/Queen.h"

Queen::Queen(std::string name, Color color, Position* position, Board* board) : Piece(name, color, position, board){}

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

bool Queen::isMoveAllowed(Position position) {
    return false;
}