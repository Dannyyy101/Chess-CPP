//
// Created by Daniel Stöcklein on 22.02.24.
//

#include "Output.h"

#include <utility>

/**
 * @brief Constructor for the Output class.
 *
 * Initializes the field_ array to a 2D grid of spaces.
 */

Output::Output(int fieldWidth, int fieldHeight) :
field_(400, std::vector<std::string>(400)),
fieldWidth_(fieldWidth),
fieldHeight_(fieldHeight+1),
boardWidth_(fieldWidth * 8 + 1),
// +1 so the count of '|' equals the height
boardHeight_((fieldHeight+1) * 8 + 1)

{

}

Output::~Output() = default;

/**
 * @brief Draws a single character at a specific position.
 *
 * This function prints the specified character at the given position on the screen.
 *
 * @param pos A pointer to a Position object representing the position where the character should be printed.
 * @param character The character that should be printed.
 *
 * @see Position
 */

void Output::drawCharacter(const Position* pos, std::string character) {
    field_[pos->getY()][pos->getX()] = std::move(character);
    delete pos;
}

void Output::drawSameCharacter(const Position* pos, int width, const std::string& character) {
    for (int i = 0; i < width; ++i) {
        drawCharacter(new Position((pos->getX()+i), pos->getY()), character);
    }
}

void Output::drawEmptySquare(const Position * pos, int width, int height) {
    // draws top border
    if(pos->getX() == boardWidth_ - fieldWidth_ - 1) {
        drawSameCharacter(new Position(pos->getX(), pos->getY()), width, "-");
    }else{
        drawSameCharacter(new Position(pos->getX(), pos->getY()), width-1, "-");
    }

    // draws left and right border
    for (int i = 0; i < height-1; ++i) {
        drawCharacter(new Position(pos->getX(), pos->getY()+i+1), "|");
        drawSameCharacter(new Position(pos->getX()+1, pos->getY()+i+1), width-2, " ");
        if(pos->getX() == boardWidth_ - fieldWidth_ - 1){
            drawCharacter(new Position(pos->getX()+width, pos->getY()+i+1), "|");
        }
    }

    // draws bottom border and the end of the board
    if(pos->getY() == boardHeight_ - fieldHeight_ - 1){
        // draws in the bottom right corner one '-' more
        if(pos->getX() == boardWidth_ - fieldWidth_ - 1) {
            drawSameCharacter(new Position(pos->getX(), pos->getY()+height), width, "-");
        }else{
        drawSameCharacter(new Position(pos->getX(), pos->getY()+height), width-1, "-");
        }
    }
}


void Output::drawSquareWithPiece(const Position* pos, int width, int height, std::string piece) {
    drawEmptySquare(pos, width, height);
    drawCharacter(new Position(pos->getX()+(fieldWidth_ / 2), pos->getY() + (fieldHeight_ / 2)), std::move(piece));
}

void Output::drawBoard(stringBoard f) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            auto* p = new Position((j * fieldWidth_), (i * (fieldHeight_)));

            if (f[i][j].empty()) {
                drawEmptySquare(p, fieldWidth_, fieldHeight_);
            }else{
                drawSquareWithPiece(p, fieldWidth_, fieldHeight_, f[i][j]);
            }
        }
    }
}

void Output::printBoard() {
    for (int i = boardHeight_; i >= 0; --i) {
        for (unsigned int j = 0; j < boardWidth_; ++j) {
            std::cout << field_[i][j];
        }
        std::cout << "\n";
    }
}