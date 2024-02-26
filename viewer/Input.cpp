//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Input.h"

Input::Input(std::istream &istream) {
    istream >> this->input_;
}

Input::~Input() = default;

std::string Input::getInput() {
    return this->input_;
}

bool Input::isNameValid(const std::string& name) {
    if(name.length() < 3){
        return false;
    }
    return true;
}

bool Input::isInputValid(const Position& pos) {
    if(pos.getX() > 7 || pos.getY() > 7){
        return false;
    }
    return true;
}

Position* Input::convertCommand() {

    unsigned int x = this->input_.at(0) - 'a';
    unsigned int y = this->input_.at(1) - '0' - 1; // -1 because of index 0 in arrays

    if(input_.length() != 2 || !isInputValid({x,y})){
        throw std::exception();
    }

    return new Position(x, y);
}
