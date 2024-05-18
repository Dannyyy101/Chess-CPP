//
// Created by Daniel Stöcklein on 25.02.24.
//

#include <utility>

#include "include/model/pieces/Queen.h"
#include "include/model/pieces/Rook.h"
#include "include/model/pieces/Bishop.h"

Queen::Queen(std::string name, Color color, Position* position, Board* board) : Piece(std::move(name), color, position, board){}

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
    Piece* rook = new Rook("Rook", this->getColor(), this->getPosition(), this->getBoard());
    Piece* bishop = new Bishop("Bishop", this->getColor(), this->getPosition(), this->getBoard());
    bool rookMoveIsAllowed = rook->isMoveAllowed(position);
    bool bishopMoveIsAllowed = bishop->isMoveAllowed(position);
    delete bishop;
    delete rook;
    return rookMoveIsAllowed || bishopMoveIsAllowed;
}