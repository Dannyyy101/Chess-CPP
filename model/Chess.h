//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include <string>
#include "Player.h"
#include "model/pieces/Piece.h"

class Chess {
private:
    Player players_[2];
    bool checkmate_;
    Player currentPlayer_;
private:
    const Player& getCurrentPlayer() const;
    void startGame();
    bool isCheckmate();
    void movePiece(Piece piece_);
    std::string** getGameBoard();
    void nextPlayer();
};


#endif //CHESS_H
