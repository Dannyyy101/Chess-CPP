//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Session.h"

Session::Session(){}

Session::~Session() = default;

void Session::run() {
    this->cli_.initOutput(12, 4);

    this->cli_.getOutput().drawBoard(this->chess_.getBoard().getBoard());
    this->cli_.getOutput().printBoard();
}