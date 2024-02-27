//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_CLI_H
#define CHESS_CLI_H

#include <iostream>
#include <array>
#include <string>

#include "Output.h"

using namespace std;

class CLI {
private:
    Output* output_;
public:
    CLI();
    ~CLI();
    void initOutput(int width = 12, int height = 3);

    void startDialog();
    string createPlayer();
    void changeDisplay();
    void printCurrentPlayer(const string& name);
    void displayErrorMessage(std::string errorMessage);
    std::array<Position*, 2> getMove();

    Output& getOutput();
};


#endif //CHESS_CLI_H
