//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "include/model/Player.h"

Player::Player(std::string name, Color color) : name_(name), color_(color){}

Player::~Player() = default;

const std::string& Player::getName() {
    return this->name_;
}

Color Player::getColor() {
    return this->color_;
}