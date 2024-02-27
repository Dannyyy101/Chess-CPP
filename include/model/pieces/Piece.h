//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <iostream>
#include <array>
#include <string>

#include "core/include/Color.h"
#include "core/include/Position.h"


class Board;

class Piece {
private:
    const std::string name_;
    Position* position_;
    Color color_;
    Board* board_;
public:
    Piece(std::string name, Color color, Position* position, Board* board);
    virtual ~Piece();
    virtual std::string getName() = 0;
    virtual bool isMoveAllowed(Position position) = 0;
    void setPosition(Position* position);
    Position& getPosition();
    Color getColor();
    Board* getBoard();
};

#endif //CHESS_PIECE_H