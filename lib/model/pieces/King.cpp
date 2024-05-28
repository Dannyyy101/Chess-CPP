//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/pieces/King.h"
#include "include/model/pieces/Queen.h"

King::King(std::string name, Color color, Position *position, Board *board) : Piece(name, color, position, board) {}

King::~King() = default;

std::string King::getName() {
    std::string s;
    s += "\x1B[";
    if (this->getColor() == WHITE) {
        s += "37m";
    } else if (this->getColor() == BLACK) {
        s += "30m";
    }

    s += "K\033[0m";

    return s;
}

bool King::isMoveAllowed(Position position) {
    int x = this->getPosition()->getX() - position.getX();
    int y = this->getPosition()->getY() - position.getY();
    if(abs(x) > 1 || abs(y) > 1){
        return false;
    }
    Queen queen("Queen", this->getColor(), this->getPosition(), this->getBoard());

    return queen.isMoveAllowed(position);
}