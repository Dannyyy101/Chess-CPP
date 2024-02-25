//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef SESSION_H
#define SESSION_H

#include "viewer/CLI.h"
#include "model/Chess.h"

class Session {
private:
    CLI cli_;
    Chess chess_;
public:
    void run();
};


#endif //SESSION_H
