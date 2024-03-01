//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/Board.h"
#include "include/model/pieces/Bishop.h"

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
    Board* board = this->getBoard();
    Position* bishopPosition = this->getPosition();

    int x = bishopPosition->getX() - position.getX();
    int y = bishopPosition->getY() - position.getY();

    unsigned int xBishop = bishopPosition->getX();
    unsigned int yBishop = bishopPosition->getY();

    int countX = 0;
    int countY = 0;

    for(int i = 1; i <= (x<0?x*-1:x);){
        i++;
        x < 0 ? countX++ : countX--;
        y < 0 ? countY++ : countY--;
        if(countX + bishopPosition->getX() == position.getX() && countY + bishopPosition->getY() == position.getY()){
            return true;
        }
        if(board->getField(new Position(countX + xBishop, countY + yBishop))->getPiece() != nullptr){
            return false;
        }
    }
    return false;
}