//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/pieces/Pawn.h"
#include "include/model/Board.h"

Pawn::Pawn(std::string name, Color color, Position *position, Board *board) : Piece(name, color, position, board),
                                                                              isMoved(false) {}

Pawn::~Pawn() = default;

std::string Pawn::getName() {
    std::string s;
    s += "\x1B[";
    if (this->getColor() == WHITE) {
        s += "37m";
    } else if (this->getColor() == BLACK) {
        s += "30m";
    }

    s += "P\033[0m";

    return s;
}

bool Pawn::isMoveAllowed(Position position) {

    switch (this->getColor()) {
        case WHITE:
            return whiteMove(position);
        case BLACK:
            return blackMove(position);
        default:
            this->isMoved = true;
    }
    return false;
}

bool Pawn::whiteMove(Position position) {
    Position posPiece = this->getPosition();
    Board *board = this->getBoard();
    // check if move takes enemy piece on the right and left
    if ((posPiece.getX() + 1 == position.getX() && posPiece.getY() + 1 == position.getY()) ||
        posPiece.getX() - 1 == position.getX() && posPiece.getY() + 1 == position.getY()) {

        // if field has a piece and the pieces color is not the same as the moved piece
        if (board->getField(&position)->getPiece() != nullptr &&
            board->getField(&position)->getPiece()->getColor() != this->getColor()) {
            return true;
        }
        return false;
    }

    // check if destination field is empty
    if(board->getField(&position)->getPiece() != nullptr){
        return false;
    }

    // check if a piece is between move
    for (unsigned int i = posPiece.getY() + 1; i < position.getY(); i++) {
        std::cout << posPiece.getY() + 1 << " " << position.getY() << std::endl;
        if (board->getField(new Position(posPiece.getX(), i))->getPiece() != nullptr) {
            throw std::runtime_error("Invalid move, there is a piece blocking your move");
        }
    }

    // check if move is one field forward
    if (posPiece.getY() + 1 == position.getY() && posPiece.getX() == position.getX()) {
        return true;
    }
    // check if move is two fields forward, if pawn hasn't moved yet
    if (!isMoved && posPiece.getY() + 2 == position.getY() && posPiece.getX() == position.getX()) {
        return true;
    }
    return false;
}

bool Pawn::blackMove(Position position) {
    Position posPiece = this->getPosition();
    Board *board = this->getBoard();
    // check if move takes enemy piece on the right and left

    std::cout << posPiece.getX() + 1 << " " << position.getX() << " " << posPiece.getY()-1 << " " << position.getY() << std::endl;

    if ((posPiece.getX() + 1 == position.getX() && posPiece.getY()-1 == position.getY()) ||
        posPiece.getX() - 1 == position.getX() && posPiece.getY()-1 == position.getY()) {

        // if field has a piece and the pieces color is not the same as the moved piece
        if (board->getField(&position)->getPiece() != nullptr &&
            board->getField(&position)->getPiece()->getColor() != this->getColor()) {
            return true;
        }
        return false;
    }

    // check if destination field is empty
    if(board->getField(&position)->getPiece() != nullptr){
        return false;
    }

    // check if a piece is between move
    for (unsigned int i = posPiece.getY() - 1; i > position.getY(); i--) {
        if (board->getField(new Position(posPiece.getX(), i))->getPiece() != nullptr) {
            throw std::runtime_error("Invalid move, there is a piece blocking your move");
        }
    }

    // check if move is one field forward
    if (posPiece.getY() - 1 == position.getY() && posPiece.getX() == position.getX()) {
        return true;
    }
    // check if move is two fields forward, if pawn hasn't moved yet
    if (!isMoved && posPiece.getY() - 2 == position.getY() && posPiece.getX() == position.getX()) {
        return true;
    }
    return false;
}