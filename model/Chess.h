//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H


#include "Player.h"
#include "Board.h"

class Chess {
private:
    Player* player_[2];
    int playerIndex;
    Player* currentPlayer;
    Board board_;
    bool gameStarted;
public:
    Chess();
    ~Chess();
    void addPlayer(std::string name);
    Board& getBoard();

    void setGameStarted();
    bool getGameStarted();
    const std::string& getCurrentPlayer() const;
    void nextPlayer();
};


#endif //CHESS_CHESS_H
