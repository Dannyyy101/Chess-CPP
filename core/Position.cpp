//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Position.h"

Position::Position(const unsigned int x, const unsigned int y) : x_(x), y_(y){}

Position::~Position() = default;

unsigned int Position::getX() const {
    return this->x_;
}

unsigned int Position::getY() const {
    return this->y_;
}