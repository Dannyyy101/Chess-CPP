#include <iostream>
#include "core/Position.h"
#include "core/Color.h"
#include "model/pieces/Piece.h"
#include "model/pieces/Pawn.h"
#include "model/pieces/Knight.h"
#include "model/Field.h"
#include "model/Board.h"
#include "viewer/Output.h"
#include "presenter/Session.h"

int main() {
    Session* session = new Session();
    session->run();

    return 0;
}
