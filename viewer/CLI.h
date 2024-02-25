//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef SCHACH_CLI_H
#define SCHACH_CLI_H

#include <iostream>
#include <string>
#include "core/Position.h"

class CLI {
public:
    std::string drawBoard();
    Position checkInput();
};


#endif //SCHACH_CLI_H
