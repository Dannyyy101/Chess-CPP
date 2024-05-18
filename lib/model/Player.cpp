//
// Created by Daniel Stöcklein on 25.02.24.
//

#include <utility>

#include "include/model/Player.h"

Player::Player(std::string name, Color color) : name_(std::move(name)), color_(color), isChecked(false), pieces(){}

Player::~Player() = default;

const std::string& Player::getName() {
    return this->name_;
}

Color Player::getColor() {
    return this->color_;
}

void Player::addPiece(Piece* piece){
    this->pieces.push_back(piece);
}

std::vector<Piece *> * Player::getPieces(){
    return &this->pieces;
}