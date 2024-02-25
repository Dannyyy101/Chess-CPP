//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_FIELD_H
#define CHESS_FIELD_H


#include "./Pieces/Piece.h"
#include "../core/Color.h"

class Field {
private:
    Color color_;
    Piece* piece_;
public:
    Field(Color color, Piece* piece);
    ~Field();
    void setPiece(Piece* piece);
    Piece* getPiece();
};


#endif //CHESS_FIELD_H
