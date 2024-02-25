//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_INPUT_H
#define CHESS_INPUT_H

#include <iostream>
#include "core/Position.h"

class Input {

public:
    Input(std::string input_);
    bool isCommandValid();
    Position convertCommand();
};


#endif //CHESS_INPUT_H
