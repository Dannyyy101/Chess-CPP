//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_SESSION_H
#define CHESS_SESSION_H


#include "include/model/Chess.h"
#include "include/viewer/CLI.h"

class Session {
private:
    Chess chess_;
    CLI cli_;
public:
    Session();
    ~Session();
    void run();
};


#endif //CHESS_SESSION_H
