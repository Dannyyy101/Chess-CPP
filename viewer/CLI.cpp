//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "CLI.h"

#include "Input.h"

CLI::CLI() : output_(nullptr) {
}

CLI::~CLI() {

}

Output &CLI::getOutput() {
    return *this->output_;
}

void CLI::initOutput(int width, int height) {
    this->output_ = new Output(width, height);
}

void CLI::startDialog() {
    cout << "Welcome to Chess\n";
    cout << "Please add some player: [p]\n";
    cout << "Change display settings: [o]\n";
    cout << "Start game: [s]\n";
}

string CLI::createPlayer() {
    int index = 1;
    cout << "Player " << index++ << "enter your name: ";
    Input in(cin);
    if (in.isNameValid(in.getInput())) {
        return in.getInput();
    }
}

void CLI::changeDisplay() {
    try {
        cout << "Please enter your preferred width: ";
        Input xIn(cin);
        int x = stoi(xIn.getInput());

        cout << "Please enter your preferred height: ";
        Input yIn(cin);
        int y = stoi(yIn.getInput());

        if (x < 1 || y < 1 || x > 48 || y > 48) {
            throw exception();
        }
        delete output_;
        output_ = new Output(x, y);
    } catch (exception &e) {
        cout << "There was an error with your input. Please use only numbers between 1 and 48";
        changeDisplay();
    }
}

void CLI::printCurrentPlayer(const string& name) {
    cout << name << ": " << endl;
}

array<Position*, 2> CLI::getMove() {
    array<Position*, 2> pos;
    cout << "Please enter the coordinates of the piece you want to move: ";
    Input pieceIn(cin);
    cout << "Please enter the coordinates of the position you want your piece to be moved: ";
    Input positionIn(cin);

    try {
        Position *pieceToMove = pieceIn.convertCommand();
        Position *positionToMoveTo = positionIn.convertCommand();
        pos[0] = pieceToMove;
        pos[1] = positionToMoveTo;

        return pos;
    } catch (exception &e) {
        cout << "Invalid move, try again";
        return getMove();
    }
}