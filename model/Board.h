//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <iostream>
#include <string>
#include <array>

#include "Field.h"

typedef std::array<std::array<Field*, 8>, 8> board;
typedef std::array<std::array<std::string, 8>, 8> stringBoard;

class Board {
private:
    board field_;
public:
    Board();
    ~Board();
    stringBoard getBoard();
};


#endif //CHESS_BOARD_H
