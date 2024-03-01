//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/pieces/Rook.h"
#include "include/model/Board.h"

Rook::Rook(std::string name, Color color, Position *position, Board *board) : Piece(name, color, position, board) {}

Rook::~Rook() = default;

std::string Rook::getName() {
    std::string s;
    s += "\x1B[";
    if (this->getColor() == WHITE) {
        s += "37m";
    } else if (this->getColor() == BLACK) {
        s += "30m";
    }

    s += "R\033[0m";

    return s;
}

bool Rook::isMoveAllowed(Position position) {
    Board *board = this->getBoard();
    Position *rookPosition = this->getPosition();

    int x = rookPosition->getX() - position.getX();
    int y = rookPosition->getY() - position.getY();

    unsigned int xRook = rookPosition->getX();
    unsigned int yRook = rookPosition->getY();

    // before check if move is allowed Rook move
    if(xRook - position.getX() != 0 && yRook - position.getY() != 0){
        return false;
    }

    int counter = 0;
    int index = (x != 0 ? x : y);
    std::cout << index << std::endl;
    for (int i = 1; i <= (index < 0 ? index * -1 : index);) {

        i++;
        if(rookPosition->getX() != position.getX()){
            x < 0 ? counter++ : counter--;
            if(board->getField(new Position(xRook + counter, yRook))->getPiece() != nullptr){
                return false;
            }
            if(xRook+counter == position.getX()){
                return true;
            }
        }

        if(rookPosition->getY() != position.getY()){
            y < 0 ? counter++ : counter--;
            std::cout << yRook + counter << std::endl;
            if(yRook+counter == position.getY()){
                return true;
            }
            if(board->getField(new Position(xRook, yRook + counter))->getPiece() != nullptr){
                return false;
            }
        }
    }
    return false;
}