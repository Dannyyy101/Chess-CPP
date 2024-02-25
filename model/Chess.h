//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H


#include "Player.h"
#include "Board.h"

class Chess {
private:
    Board board_;
public:
    Chess();
    ~Chess();
    Board& getBoard();
};


#endif //CHESS_CHESS_H
