//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/Chess.h"

#include <utility>

Chess::Chess() : currentPlayer(nullptr), playerIndex(0), board_(new Board) {
    player_[0] = nullptr;
    player_[1] = nullptr;
}

Chess::~Chess() {
    for (Player *player: player_) {
        delete player;
    }
    delete board_;
}

Board &Chess::getBoard() {
    return *this->board_;
}

void Chess::addPlayer(std::string name) {
    if (player_[0] == nullptr) {
        player_[0] = new Player(std::move(name), WHITE);
    } else {
        player_[1] = new Player(std::move(name), BLACK);
    }
}


void Chess::setGameStarted() {
    this->gameStarted = true;
    for (int i = 0; i < 8; ++i) {
        player_[0]->addPiece(board_->getField(new Position(i, 0))->getPiece());
        player_[0]->addPiece(board_->getField(new Position(i, 1))->getPiece());
        player_[1]->addPiece(board_->getField(new Position(i, 6))->getPiece());
        player_[1]->addPiece(board_->getField(new Position(i, 7))->getPiece());
    }
    nextPlayer();
}

bool Chess::getGameStarted() {
    this->board_->initBoard();
    return this->gameStarted;
}

const std::string &Chess::getCurrentPlayer() const {
    return this->currentPlayer->getName();
}

void Chess::nextPlayer() {
    currentPlayer = this->player_[(playerIndex = playerIndex % 2)];
    playerIndex++;
}

bool Chess::isPlayerInCheck() {
    std::vector<Piece *> *pieces = this->currentPlayer->getPieces();
    Piece *king;
    for (auto p: *pieces) {
        if (p->getName().find("K")) {
            king = p;
            break;
        }
    }
    Position *positionKing = king->getPosition();
    this->nextPlayer();
    std::vector<Piece *> *piecesNextPlayer = this->currentPlayer->getPieces();
    this->nextPlayer();
    for (auto p: *piecesNextPlayer) {
        if (p->isMoveAllowed(*positionKing)) {
            return true;
        }
    }

    return false;
}

void Chess::makeMove(std::array<Position *, 2> move) {
    if (board_->getField(move[0])->getPiece() == nullptr) {
        throw std::runtime_error("There is no piece on this field.");
    }
    Piece *pieceToMove = board_->getField(move[0])->getPiece();
    if (pieceToMove->getColor() != this->currentPlayer->getColor()) {
        throw std::runtime_error("You do not own this piece.");
    }
    if (!pieceToMove->isMoveAllowed({move[1]->getX(), move[1]->getY()})) {
        throw std::runtime_error("This move is not allowed.");
    }
    if (isPlayerInCheck()) {
        board_->movePiece(move);
        if (isPlayerInCheck()) {
            // reverse the move, because he was invalid
            board_->movePiece(std::array<Position *, 2>{move[1], move[0]});
            throw std::runtime_error("You are checked, move a other piece.");
        }
    }
    board_->movePiece(move);
}

bool Chess::canMoveBeBlocked(Piece *pieceEnemy, Position posEnemy, Piece *king, Position posKing) {
    // check if piece can be taken
    std::vector<Piece *> *piecesPlayer = this->currentPlayer->getPieces();

    for (auto p: *piecesPlayer) {
        if (p->isMoveAllowed(posEnemy)) {
            return true;
        }
    }

    // check if piece can Block Enemy
    if (!pieceEnemy->getName().find('R')) {
        int xPositive, yPositive;
        xPositive = posEnemy.getX() < posKing.getX() ? 1 : -1;
        yPositive = posEnemy.getY() < posKing.getY() ? 1 : -1;

        int x = posEnemy.getX();
        int y = posEnemy.getY();

        while (x != posKing.getX() || y != posKing.getY()) {
            for (auto p: *piecesPlayer) {
                Position position(x, y);
                if (p->isMoveAllowed(position)) {
                    return true;
                }
            }
            if (x != posKing.getX()) {
                x = x + 1 * xPositive;
            }
            if (y != posKing.getY()) {
                y = y + 1 * yPositive;
            }
        }
    }

    return false;
}

bool Chess::canKingMove(Piece *king, Position posKing) {
    if(king->isMoveAllowed({posKing.getX(), posKing.getY()})){

    }
}

bool Chess::isGameOver() {
    std::vector<Piece *> *pieces = this->currentPlayer->getPieces();
    Piece *king;
    for (auto p: *pieces) {
        std::cout << p->getName();
        if (p->getName().find('K')) {
            king = p;
            break;
        }
    }
    Position *positionKing = king->getPosition();
    this->nextPlayer();
    std::vector<Piece *> *piecesNextPlayer = this->currentPlayer->getPieces();
    this->nextPlayer();
    for (auto p: *piecesNextPlayer) {
        if (p->isMoveAllowed(*positionKing)) {
            if (canMoveBeBlocked(p, *p->getPosition(), king, *positionKing)) {
                continue;
            } else {
                this->gameStarted = false;
                return true;
            }
        }
    }

    return false;
}