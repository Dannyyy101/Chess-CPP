//
// Created by Daniel Stöcklein on 25.02.24.
//


#include "include/model/Board.h"

#include "include/model/pieces/Pawn.h"
#include "include/model/pieces/Knight.h"
#include "include/model/pieces/Rook.h"
#include "include/model/pieces/Bishop.h"
#include "include/model/pieces/Queen.h"
#include "include/model/pieces/King.h"


Board::Board() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            field_[i][j] = new Field(((j + i) % 2 == 0) ? BLACK : WHITE, nullptr);
        }
    }
}

Board::~Board() {}

void Board::initBoard() {
    // init Fields

    field_[0][0]->setPiece(new Rook("Rook", WHITE, new Position(0, 0), this));
    field_[0][1]->setPiece(new Knight("Knight", WHITE, new Position(1, 0), this));
    field_[0][2]->setPiece(new Bishop("Bishop", WHITE, new Position(2, 0), this));
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
    field_[7][3]->setPiece(new Queen("King", BLACK, new Position(3, 7), this));
    field_[7][4]->setPiece(new King("Queen", BLACK, new Position(4, 7), this));
    field_[7][5]->setPiece(new Bishop("Bishop", BLACK, new Position(5, 7), this));
    field_[7][6]->setPiece(new Knight("Knight", BLACK, new Position(6, 7), this));
    field_[7][7]->setPiece(new Rook("Rook", BLACK, new Position(7, 7), this));

    for (unsigned int i = 0; i < 8; ++i) {
        field_[6][i]->setPiece(new Pawn("Pawn", BLACK, new Position(i, 6), this));
    }
}

void Board::boardTest(const std::vector<Piece *>& pieces) {
    for (auto p: pieces) {
        unsigned int x = p->getPosition()->getX();
        unsigned int y = p->getPosition()->getY();

        field_[y][x]->setPiece(p);
    }
}

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

Field *Board::getField(Position* pos) {
    return field_[pos->getY()][pos->getX()];
}

void Board::movePiece(std::array<Position *, 2> pos) {
    Field *field = field_[pos[0]->getY()][pos[0]->getX()];
    Piece *piece = field->getPiece();
    Position* oldPos = piece->getPosition();
    delete oldPos;
    piece->setPosition(new Position(pos[1]->getX(), pos[1]->getY()));
    field_[pos[1]->getY()][pos[1]->getX()]->setPiece(piece);
    field->setPiece(nullptr);
    delete pos[0];
}