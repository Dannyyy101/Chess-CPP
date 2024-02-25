//
// Created by Daniel Stöcklein on 21.02.24.
//

#ifndef BISHOP_H
#define BISHOP_H


#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(Color);
    ~Bishop();
    const std::string toString() const;
};


#endif //BISHOP_H
