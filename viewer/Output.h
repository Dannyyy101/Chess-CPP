//
// Created by Daniel Stöcklein on 25.02.24.
//

#ifndef CHESS_OUTPUT_H
#define CHESS_OUTPUT_H

#include <iostream>
#include <array>
#include <string>
#include <vector>

#include "../core/Position.h"

typedef std::array<std::array<std::string, 8>, 8> stringBoard;

typedef std::vector<std::vector<std::string>> paintBoard;

class Output {
private:
    paintBoard field_;

    const unsigned int fieldHeight_;
    const unsigned int fieldWidth_;

    const unsigned int boardHeight_;
    const unsigned int boardWidth_;
public:
    Output(int fieldWidth = 13, int fieldHeight = 3);
    ~Output();

    void drawCharacter(const Position* pos, std::string character);
    void drawSameCharacter(const Position* pos, unsigned int width, const std::string& character);
    void drawEmptySquare(const Position * pos, unsigned int width, unsigned int height);
    void drawSquareWithPiece(const Position* pos, unsigned int width, unsigned int height, std::string piece);
    void drawBoard(stringBoard);
    void printBoard();
};


#endif //CHESS_OUTPUT_H
