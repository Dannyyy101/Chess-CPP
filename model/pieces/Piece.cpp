//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Piece.h"

Piece::Piece(std::string name, Color color) : name_(name), color_(color){}

Piece::~Piece() = default;

Color Piece::getColor() {
    return this->color_;
}