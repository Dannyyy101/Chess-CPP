//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_OUTPUT_H
#define CHESS_OUTPUT_H

#include <iostream>
#include <string>
#include "model/Field.h"
#include "core/Position.h"

class Output {
private:
    Field** field_;
public:
    Position drawCharacter(Position at);
    Position drawSameCharacter(Position at);
    Position drawEmptySquare(Position at);
    Position drawInsideSquare(Position at);
    Position drawBoard(Position at);
};


#endif //CHESS_OUTPUT_H
