//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H


#include "Player.h"
#include "Board.h"
#include "core/include/Position.h"

class Chess {
private:
    Player *player_[2];
    int playerIndex;
    Player *currentPlayer;
    Board *board_;
    bool gameStarted;
public:
    Chess();

    ~Chess();

    void addPlayer(std::string name);

    Board &getBoard();

    void setGameStarted();

    bool getGameStarted();

    const std::string &getCurrentPlayer() const;

    void makeMove(std::array<Position *, 2> move);

    void nextPlayer();

    bool isPlayerInCheck();

    bool canKingMove(Piece *king, Position posKing);

    bool isGameOver();

    bool canMoveBeBlocked(Piece *pieceEnemy, Position posEnemy, Piece *king, Position posKing);
};


#endif //CHESS_CHESS_H
