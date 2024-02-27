//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "Board.h"

#include "pieces/Pawn.h"
#include "pieces/Knight.h"
#include "pieces/Rook.h"
#include "pieces/Bishop.h"
#include "pieces/Queen.h"
#include "pieces/King.h"


Board::Board() {
    // init Fields
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            field_[i][j] = new Field(((j + i) % 2 == 0) ? BLACK : WHITE, nullptr);
        }
    }

    field_[0][0]->setPiece(new Rook("Rook", WHITE, new Position(0, 0), this));
    field_[0][1]->setPiece(new Knight("Knight", WHITE, new Position(1, 0), this));
    field_[5][2]->setPiece(new Bishop("Bishop", WHITE, new Position(2, 5), this));
    field_[0][3]->setPiece(new Queen("Queen", WHITE, new Position(3, 0), this));
    field_[0][4]->setPiece(new King("King", WHITE, new Position(4, 0), this));
    field_[0][5]->setPiece(new Bishop("Bishop", WHITE, new Position(5, 0), this));
    field_[0][6]->setPiece(new Knight("Knight", WHITE, new Position(6, 0), this));
    field_[0][7]->setPiece(new Rook("Rook", WHITE, new Position(7, 0), this));

    for (unsigned int i = 0; i < 8; ++i) {
        field_[1][i]->setPiece(new Pawn("Pawn", WHITE, new Position(i, 1), this));
    }

    field_[7][0]->setPiece(new Rook("Rook", BLACK, new Position(0, 7), this));
    field_[7][1]->setPiece(new Knight("Knight", BLACK, new Position(1, 7), this));
    field_[7][2]->setPiece(new Bishop("Bishop", BLACK, new Position(2, 7), this));
    field_[2][1]->setPiece(new Queen("King", BLACK, new Position(1, 2), this));
    field_[7][4]->setPiece(new King("Queen", BLACK, new Position(4, 7), this));
    field_[7][5]->setPiece(new Bishop("Bishop", BLACK, new Position(5, 7), this));
    field_[7][6]->setPiece(new Knight("Knight", BLACK, new Position(6, 7), this));
    field_[7][7]->setPiece(new Rook("Rook", BLACK, new Position(7, 7), this));

    for (unsigned int i = 0; i < 8; ++i) {
        field_[6][i]->setPiece(new Pawn("Pawn", BLACK, new Position(i, 6), this));
    }
}

Board::~Board() {}

stringBoard Board::getBoard() {
    stringBoard board;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (field_[i][j]->getPiece() == nullptr) {
                board[i][j] = "";
            } else {
                board[i][j] = field_[i][j]->getPiece()->getName();
            }
        }
    }
    return board;
}

Field *Board::getField(Position *pos) {
    return field_[pos->getY()][pos->getX()];
}

void Board::movePiece(std::array<Position *, 2> pos) {
    Field *field = field_[pos[0]->getY()][pos[0]->getX()];
    Piece *piece = field->getPiece();
    piece->setPosition(new Position(pos[1]->getX(), pos[1]->getY()));
    field_[pos[1]->getY()][pos[1]->getX()]->setPiece(piece);
    field->setPiece(nullptr);
}