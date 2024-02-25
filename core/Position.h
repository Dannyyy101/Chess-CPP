//
// Created by Anim️ on 21.02.24.
//
#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H

class Position {
private:
    const unsigned int x_;
    const unsigned int y_;
public:
    Position(unsigned int x, unsigned int y);
    unsigned int getX();
    unsigned int getY();
};

#endif //CHESS_POSITION_H