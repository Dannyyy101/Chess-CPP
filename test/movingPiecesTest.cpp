#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"
#include "include/model/Board.h"
#include "include/model/pieces/King.h"
#include "include/model/pieces/Queen.h"
#include "include/model/pieces/Rook.h"
#include "include/model/pieces/Bishop.h"
#include "include/model/pieces/Knight.h"
#include "include/model/pieces/Pawn.h"
#include "include/model/Chess.h"
#include <vector>

// Helper function to set up the board
void setupBoard(Board &board, Piece *piece) {
    board.boardTest(std::vector<Piece *>{piece});
}

void setupBoardWithMultiplePieces(Board &board, const std::vector<Piece *> &pieces) {
    board.boardTest(pieces);
}

// King tests
TEST(KingMoveTest, KingValidMoves) {
    Board board;
    auto *king = new King("King", WHITE, new Position(4, 4), &board);
    setupBoard(board, king);

    EXPECT_TRUE(king->isMoveAllowed({3, 3}));
    EXPECT_TRUE(king->isMoveAllowed({4, 5}));
    EXPECT_TRUE(king->isMoveAllowed({5, 4}));

    delete king;
}

TEST(KingMoveTest, KingInvalidMoves) {
    Board board;
    auto *king = new King("King", WHITE, new Position(4, 4), &board);
    setupBoard(board, king);

    EXPECT_FALSE(king->isMoveAllowed({6, 6}));
    EXPECT_FALSE(king->isMoveAllowed({2, 4}));

    delete king;
}

// Queen tests
TEST(QueenMoveTest, QueenValidMoves) {
    Board board;
    auto *queen = new Queen("Queen", WHITE, new Position(4, 4), &board);
    setupBoard(board, queen);

    EXPECT_TRUE(queen->isMoveAllowed({4, 7}));
    EXPECT_TRUE(queen->isMoveAllowed({7, 7}));
    EXPECT_TRUE(queen->isMoveAllowed({0, 4}));

    delete queen;
}

TEST(QueenMoveTest, QueenInvalidMoves) {
    Board board;
    auto *queen = new Queen("Queen", WHITE, new Position(4, 4), &board);
    setupBoard(board, queen);

    EXPECT_FALSE(queen->isMoveAllowed({5, 2}));
    EXPECT_FALSE(queen->isMoveAllowed({6, 3}));

    delete queen;
}

// Rook tests
TEST(RookMoveTest, RookValidMoves) {
    Board board;
    auto *rook = new Rook("Rook", WHITE, new Position(4, 4), &board);
    setupBoard(board, rook);

    EXPECT_TRUE(rook->isMoveAllowed({4, 7}));
    EXPECT_TRUE(rook->isMoveAllowed({4, 0}));
    EXPECT_TRUE(rook->isMoveAllowed({7, 4}));

    delete rook;
}

TEST(RookMoveTest, RookInvalidMoves) {
    Board board;
    auto *rook = new Rook("Rook", WHITE, new Position(4, 4), &board);
    setupBoard(board, rook);

    EXPECT_FALSE(rook->isMoveAllowed({5, 5}));
    EXPECT_FALSE(rook->isMoveAllowed({3, 3}));

    delete rook;
}

// Bishop tests
TEST(BishopMoveTest, BishopValidMoves) {
    Board board;
    auto *bishop = new Bishop("Bishop", WHITE, new Position(4, 4), &board);
    setupBoard(board, bishop);

    EXPECT_TRUE(bishop->isMoveAllowed({6, 6}));
    EXPECT_TRUE(bishop->isMoveAllowed({2, 2}));
    EXPECT_TRUE(bishop->isMoveAllowed({5, 3}));

    delete bishop;
}

TEST(BishopMoveTest, BishopInvalidMoves) {
    Board board;
    auto *bishop = new Bishop("Bishop", WHITE, new Position(4, 4), &board);
    setupBoard(board, bishop);

    EXPECT_FALSE(bishop->isMoveAllowed({4, 5}));
    EXPECT_FALSE(bishop->isMoveAllowed({3, 4}));

    delete bishop;
}

// Knight tests
TEST(KnightMoveTest, KnightValidMoves) {
    Board board;
    auto *knight = new Knight("Knight", WHITE, new Position(4, 4), &board);
    setupBoard(board, knight);

    EXPECT_TRUE(knight->isMoveAllowed({6, 5}));
    EXPECT_TRUE(knight->isMoveAllowed({5, 6}));
    EXPECT_TRUE(knight->isMoveAllowed({2, 3}));

    delete knight;
}

TEST(KnightMoveTest, KnightInvalidMoves) {
    Board board;
    auto *knight = new Knight("Knight", WHITE, new Position(4, 4), &board);
    setupBoard(board, knight);

    EXPECT_FALSE(knight->isMoveAllowed({4, 6}));
    EXPECT_FALSE(knight->isMoveAllowed({3, 3}));

    delete knight;
}

// Pawn tests
TEST(PawnMoveTest, PawnValidMoves) {
    Board board;
    auto *pawn = new Pawn("Pawn", WHITE, new Position(4, 4), &board);
    setupBoard(board, pawn);

    EXPECT_TRUE(pawn->isMoveAllowed({4, 5}));  // Forward move
    EXPECT_TRUE(pawn->isMoveAllowed({4, 6}));  // Double move from initial position

    delete pawn;
}

TEST(PawnMoveTest, PawnInvalidMoves) {
    Board board;
    auto *pawn = new Pawn("Pawn", WHITE, new Position(4, 4), &board);
    setupBoard(board, pawn);

    EXPECT_FALSE(pawn->isMoveAllowed({4, 3}));  // Backward move
    EXPECT_FALSE(pawn->isMoveAllowed({5, 5}));  // Diagonal move without capture

    delete pawn;
}

TEST(CheckTest, isPlayerInCheck) {
    auto *chess = new Chess();
    chess->addPlayer("Daniel");
    chess->addPlayer("Felix");

    auto board = new Board();
    auto *queen1 = new Queen("Queen1", WHITE, new Position(3, 3), board);
    auto *queen2 = new Queen("Queen2", WHITE, new Position(5, 5), board);
    auto *king = new King("King", BLACK, new Position(4, 4), board);


    setupBoardWithMultiplePieces(*board, std::vector<Piece *>{queen1, queen2, king});

    chess->initBoard(board);

    chess->setGameStarted();

    EXPECT_TRUE(chess->isPlayerInCheck());

    delete queen1;
    delete queen2;
    delete king;
    delete chess;
}

TEST(GameOverTest, isGameOver) {
    auto *chess = new Chess();
    chess->addPlayer("Daniel");
    chess->addPlayer("Felix");

    auto board = new Board();
    auto *queen1 = new Queen("Queen1", WHITE, new Position(3, 3), board);
    auto *queen2 = new Queen("Queen2", WHITE, new Position(5, 5), board);
    auto *king = new King("King", BLACK, new Position(4, 4), board);


    setupBoardWithMultiplePieces(*board, std::vector<Piece *>{queen1, queen2, king});

    chess->initBoard(board);
    chess->setGameStarted();
    chess->nextPlayer();
    EXPECT_TRUE(chess->isGameOver());

    delete queen1;
    delete queen2;
    delete king;
    delete chess;
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
