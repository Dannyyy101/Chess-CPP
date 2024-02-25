//
// Created by Daniel Stöcklein on 25.02.24.
//

#include "CLI.h"

CLI::CLI() : output_(nullptr) {
}

CLI::~CLI() {

}

Output& CLI::getOutput() {
    return *this->output_;
}

void CLI::initOutput(int width, int height) {
    this->output_ = new Output(width, height);
}
