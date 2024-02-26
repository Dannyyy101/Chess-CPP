//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H

#include <iostream>
#include <string>

#include "../core/Color.h"

class Player {
private:
    const std::string name_;
    Color color_;
public:
    Player(std::string name, Color color);
    ~Player();

    const std::string& getName();
    Color getColor();
};


#endif //CHESS_PLAYER_H
