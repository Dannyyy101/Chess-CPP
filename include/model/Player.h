//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <iostream>
#include <string>
#include <vector>

#include "core/include/Color.h"
#include "include/model/pieces/Piece.h"

class Player {
private:
    const std::string name_;
    Color color_;
    bool isChecked;
    std::vector<Piece *> pieces;
public:
    Player(std::string name, Color color);
    ~Player();

    void addPiece(Piece* piece);
    std::vector<Piece *> * getPieces();
    const std::string& getName();
    Color getColor();
};


#endif //CHESS_PLAYER_H
