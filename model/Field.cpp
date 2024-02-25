//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Field.h"

Field::Field(Color color, Piece *piece) : color_(color), piece_(piece){}

Field::~Field() {}

void Field::setPiece(Piece *piece) {
    this->piece_=piece;
}

Piece *Field::getPiece() {
    return this->piece_;
}
