//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_CLI_H
#define CHESS_CLI_H


#include "Output.h"

class CLI {
private:
    Output* output_;
public:
    CLI();
    ~CLI();
    void initOutput(int width, int height);
    Output& getOutput();
};


#endif //CHESS_CLI_H
