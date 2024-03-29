cmake_minimum_required(VERSION 3.18)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess
        core/include/Color.h
        core/lib/Position.cpp
        core/include/Position.h
        lib/model/Player.cpp
        include/model/Player.h
        lib/model/pieces/Piece.cpp
        include/model/pieces/Piece.h
        lib/model/pieces/Pawn.cpp
        include/model/pieces/Pawn.h
        lib/model/pieces/Bishop.cpp
        include/model/pieces/Bishop.h
        lib/model/pieces/King.cpp
        include/model/pieces/King.h
        lib/model/pieces/Knight.cpp
        include/model/pieces/Knight.h
        lib/model/pieces/Queen.cpp
        include/model/pieces/Queen.h
        lib/model/pieces/Rook.cpp
        include/model/pieces/Rook.h
        lib/model/Field.cpp
        include/model/Field.h
        lib/model/Board.cpp
        include/model/Board.h
        Main.cpp
        lib/presenter/Session.cpp
        include/presenter/Session.h
        lib/viewer/Output.cpp
        include/viewer/Output.h
        lib/model/Chess.cpp
        include/model/Chess.h
        lib/viewer/CLI.cpp
        include/viewer/CLI.h
        lib/viewer/Input.cpp
        include/viewer/Input.h
)
