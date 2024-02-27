//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H


class Position {
private:
    const unsigned int x_;
    const unsigned int y_;
public:
    Position(unsigned int x, unsigned int y);
    ~Position();
    unsigned int getX() const;
    unsigned int getY() const;
};


#endif //CHESS_POSITION_H
