//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "Field.h"

Field::Field() : position_(0,0){

}

Field::Field(Piece piece_, Color color_, Position position_) : piece_(piece_), color_(color_), position_(position_) {

}

Color Field::getColor() {
    return this->color_;
}

Piece &Field::getPiece() {
    return this->piece_;
}

Position &Field::getPosition() {
    return this->position_;
}

void Field::setColor(Color color_) {
    this->color_ = color_;
}

void Field::setPiece(Piece piece_) {
    this->piece_ = piece_;
}
