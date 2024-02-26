//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Chess.h"

#include <utility>

Chess::Chess() : currentPlayer(nullptr), playerIndex(0){

}

Chess::~Chess() {
    for(Player* player : player_){
        delete player;
    }
}

Board &Chess::getBoard() {
    return this->board_;
}

void Chess::addPlayer(std::string name) {
    if(player_[0] == nullptr){
        player_[0] = new Player(std::move(name), WHITE);
    }
    else{
        player_[1] = new Player(std::move(name), BLACK);
    }
}


void Chess::setGameStarted() {
    this->gameStarted = true;
    nextPlayer();
}

bool Chess::getGameStarted() {
    return this->gameStarted;
}

const std::string& Chess::getCurrentPlayer() const {
    return this->currentPlayer->getName();
}

void Chess::nextPlayer() {
    currentPlayer = this->player_[(playerIndex = playerIndex % 2)];
    playerIndex++;
}
