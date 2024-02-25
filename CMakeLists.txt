cmake_minimum_required(VERSION 3.27)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Chess main.cpp
        core/Position.cpp
        core/Position.h
        core/Color.h
        model/pieces/Piece.cpp
        model/pieces/Piece.h
        model/Field.cpp
        model/Field.h
        model/pieces/Bishop.cpp
        model/pieces/Bishop.h
        model/pieces/King.cpp
        model/pieces/King.h
        model/pieces/Knight.cpp
        model/pieces/Knight.h
        model/pieces/Pawn.cpp
        model/pieces/Pawn.h
        model/pieces/Queen.cpp
        model/pieces/Queen.h
        model/pieces/Rook.cpp
        model/pieces/Rook.h
        model/Board.cpp
        model/Board.h
        viewer/CLI.cpp
        viewer/CLI.h
        presenter/Session.cpp
        presenter/Session.h
        viewer/Output.cpp
        viewer/Output.h
        model/Chess.cpp
        model/Chess.h
        viewer/Input.cpp
        viewer/Input.h
        core/ResultType.h
        model/Player.cpp
        model/Player.h
)
