cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess
        core/Color.h
        core/Position.cpp
        core/Position.h
        model/Player.cpp
        model/Player.h
        model/Pieces/Piece.cpp
        model/Pieces/Piece.h
        model/Pieces/Pawn.cpp
        model/Pieces/Pawn.h
        model/Pieces/Bishop.cpp
        model/Pieces/Bishop.h
        model/Pieces/King.cpp
        model/Pieces/King.h
        model/Pieces/Knight.cpp
        model/Pieces/Knight.h
        model/Pieces/Queen.cpp
        model/Pieces/Queen.h
        model/Pieces/Rook.cpp
        model/Pieces/Rook.h
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
)
