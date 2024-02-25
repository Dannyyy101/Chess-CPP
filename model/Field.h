//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_FIELD_H
#define CHESS_FIELD_H


#include "../core/Position.h"
#include "pieces/Piece.h"
#include "../core/Color.h"

class Field {
private:
    Color color_;
    Piece piece_;
    Position position_;
public:
    Field();
    Field(Piece piece_, Color color_, Position position_);
    Color getColor();
    Piece& getPiece();
    Position& getPosition();
    void setColor(Color color_);
    void setPiece(Piece piece_);
};


#endif //CHESS_FIELD_H
