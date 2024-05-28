//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/pieces/Knight.h"
#include "include/model/Board.h"

Knight::Knight(std::string name, Color color, Position* position, Board* board) : Piece(name, color, position, board){}

Knight::~Knight() = default;

std::string Knight::getName() {
    std::string s;
    s+="\x1B[";
    if(this->getColor() == WHITE){
        s+= "37m";
    }
    else if(this->getColor() == BLACK){
        s+= "30m";
    }

    s+="k\033[0m";

    return s;
}

bool Knight::isMoveAllowed(Position position) {
    Position* knightPosition = this->getPosition();
    int arr[2] = {2,-2};

    for(int pos : arr){
        if(knightPosition->getY()+pos == position.getY()){
            if(knightPosition->getX()+1 == position.getX()){
                return true;
            } else if(knightPosition->getX()-1 == position.getX()){
                return true;
            }
        }
    }
    for(int pos : arr){
        if(knightPosition->getX()+pos == position.getX()){
            if(knightPosition->getY()+1 == position.getY()){
                return true;
            } else if(knightPosition->getY()-1 == position.getY()){
                return true;
            }
        }
    }
    return false;
}