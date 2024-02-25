//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Field.h"
#include "../core/Position.h"

class Board {
private:
    Field** field_;
public:
    Board();
    ~Board();
    Field getField(Position position_);
    void setField(int position_);
};


#endif //CHESS_BOARD_H
