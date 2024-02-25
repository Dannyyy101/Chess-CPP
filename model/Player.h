//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "core/Color.h"
#include "model/pieces/Piece.h"

class Player {
private:
    std::string name_;
    Color color_;
    Piece* pieces_;
    bool forcedToMove_;
public:
    Piece* getPices();
    void removePiece(Piece piece_);
    void changePiece(Piece piece_);
    bool isForcedToMove();
    bool setForcedToMove();
};


#endif //PLAYER_H
