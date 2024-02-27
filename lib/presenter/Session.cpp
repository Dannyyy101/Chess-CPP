//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/presenter/Session.h"

#include "include/viewer/Input.h"

Session::Session() {}

Session::~Session() = default;

void Session::run() {
    this->cli_.initOutput();
    this->chess_.addPlayer("Daniel");
    this->chess_.addPlayer("Felix");

    this->cli_.startDialog();
    while (!this->chess_.getGameStarted()) {
        Input input(cin);
        string in = input.getInput();
        switch (in.at(0)) {
            case 'p':
                this->chess_.addPlayer(this->cli_.createPlayer());
                break;
            case 'o':
                this->cli_.changeDisplay();
                break;
            case 's':
                this->chess_.setGameStarted();
                break;
        }
    }
    while (this->chess_.getGameStarted()) {
        this->cli_.getOutput().drawBoard(this->chess_.getBoard().getBoard());
        this->cli_.getOutput().printBoard();
        this->cli_.printCurrentPlayer(this->chess_.getCurrentPlayer());
        try{
            this->chess_.makeMove(this->cli_.getMove());
        } catch (runtime_error& e){
            this->cli_.displayErrorMessage(e.what());
            this->chess_.nextPlayer();
        }

        this->chess_.nextPlayer();

    }
}