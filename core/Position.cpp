//
// Created by Anim on 21.02.24.
//

#include "Position.h"

unsigned int Position::getX() {
    return x_;
}

unsigned int Position::getY() {
    return y_;
}

Position::Position(unsigned int x, unsigned int y) : x_(x), y_(y) {

}