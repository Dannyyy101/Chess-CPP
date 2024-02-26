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


Board::Board(){
    // init Fields
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            field_[i][j] = new Field(((j + i) % 2 == 0) ? BLACK : WHITE, nullptr);
        }
    }

    field_[0][0]->setPiece(new Knight("Knight",WHITE));
    field_[0][1]->setPiece(new Rook("Rook",WHITE));
    field_[0][2]->setPiece(new Bishop("Bishop",WHITE));
    field_[0][3]->setPiece(new Queen("Queen",WHITE));
    field_[0][4]->setPiece(new King("King",WHITE));
    field_[0][5]->setPiece(new Bishop("Bishop",WHITE));
    field_[0][6]->setPiece(new Rook("Rook",WHITE));
    field_[0][7]->setPiece(new Knight("Knight",WHITE));

    for (int i = 0; i < 8; ++i) {
        field_[1][i]->setPiece(new Pawn("Pawn", WHITE));
    }

    field_[7][0]->setPiece(new Knight("Knight",BLACK));
    field_[7][1]->setPiece(new Rook("Rook",BLACK));
    field_[7][2]->setPiece(new Bishop("Bishop",BLACK));
    field_[7][3]->setPiece(new Queen("King",BLACK));
    field_[7][4]->setPiece(new King("Queen",BLACK));
    field_[7][5]->setPiece(new Bishop("Bishop",BLACK));
    field_[7][6]->setPiece(new Rook("Rook",BLACK));
    field_[7][7]->setPiece(new Knight("Knight",BLACK));

    for (int i = 0; i < 8; ++i) {
        field_[6][i]->setPiece(new Pawn("Pawn", BLACK));
    }


}

Board::~Board() {}

stringBoard Board::getBoard() {
    stringBoard board;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if(field_[i][j]->getPiece() == nullptr){
                board[i][j] = "";
            } else{
                board[i][j] = field_[i][j]->getPiece()->getName();
            }
        }
    }

    return board;
}
