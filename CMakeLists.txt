cmake_minimum_required(VERSION 3.18)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess
        core/Color.h
        core/Position.cpp
        core/Position.h
        model/Player.cpp
        model/Player.h
        model/pieces/Piece.cpp
        model/pieces/Piece.h
        model/pieces/Pawn.cpp
        model/pieces/Pawn.h
        model/pieces/Bishop.cpp
        model/pieces/Bishop.h
        model/pieces/King.cpp
        model/pieces/King.h
        model/pieces/Knight.cpp
        model/pieces/Knight.h
        model/pieces/Queen.cpp
        model/pieces/Queen.h
        model/pieces/Rook.cpp
        model/pieces/Rook.h
        model/Field.cpp
        model/Field.h
        model/Board.cpp
        model/Board.h
        Main.cpp
        presenter/Session.cpp
        presenter/Session.h
        viewer/Output.cpp
        viewer/Output.h
        model/Chess.cpp
        model/Chess.h
        viewer/CLI.cpp
        viewer/CLI.h
        viewer/Input.cpp
        viewer/Input.h
)
