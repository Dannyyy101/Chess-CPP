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

    int x = position.getX();
    int y = position.getY();

    unsigned int xRook = rookPosition->getX();
    unsigned int yRook = rookPosition->getY();

    if (x != xRook && y != yRook) {
        return false;
    }

    int rangeX = (x == xRook) ? 0 : (x > xRook) ? 1 : -1;
    int rangeY = (y == yRook) ? 0 : (y > yRook) ? 1 : -1;

    int currentX = rangeX + xRook;
    int currentY = rangeY + yRook;
    while (currentX != x || currentY != y) {
        if (board->getField(new Position(currentX, currentY))->getPiece() != nullptr) {
            return false;
        }
        currentX += rangeX;
        currentY += rangeY;
    }

    return true;
}