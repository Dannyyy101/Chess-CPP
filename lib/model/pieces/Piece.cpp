//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/pieces/Piece.h"

Piece::Piece(std::string name, Color color, Position* position, Board* board) : name_(name), color_(color), position_(position), board_(board){}

Piece::~Piece() = default;

void Piece::setPosition(Position* position) {
    this->position_ = position;
}

Position &Piece::getPosition() {
    return *this->position_;
}

Color Piece::getColor() {
    return this->color_;
}

Board *Piece::getBoard() {
    return this->board_;
}