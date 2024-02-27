//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_INPUT_H
#define CHESS_INPUT_H

#include <iostream>
#include <string>
#include "core/include/Position.h"

class Input {
private:
    std::string input_;
public:
    Input(std::istream& istream);
    ~Input();
    std::string getInput();
    static bool isNameValid(const std::string& name);
    static bool isInputValid(const Position& pos);
    Position* convertCommand();
};


#endif //CHESS_INPUT_H
