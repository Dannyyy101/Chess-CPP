//
// Created by Daniel Stöcklein on 21.02.24.
//

#include "Board.h"

Board::Board(): field_(new Field * ) {
    // init board with fields
    field_[0][0] = Field(Piece(), Color::WHITE, Position(0,0));

}

Board::~Board() {

}


Field Board::getField(Position position_) {
    return this->field_[position_.getX()][position_.getY()];
}

void Board::setField(int position_) {

}
