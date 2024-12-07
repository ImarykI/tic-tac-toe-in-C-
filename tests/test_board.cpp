#include "../gtest/include/gtest.h"
#include "../include/board.hpp"

//Verific daca tabla se initializeaza goala
TEST(BoardTest, DefaultConstructor) {
    Board board;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(board.GetPointInBoard(Point(i, j)), Sign::Empty);
        }
    }
}

// Test pentru a verifica daca validarea miscarii merge
TEST(BoardTest, MakeMove) {
    Board board;
    Point p(1, 1);
    board.MakeMove(p, Sign::X);
    EXPECT_EQ(board.GetPointInBoard(p), Sign::X);

    board.MakeMove(p, Sign::O);  // Mutarea pe aceea;i celula
    EXPECT_EQ(board.GetPointInBoard(p), Sign::X);  // Nu ar trebui să se schimbe
}

// Test pentru ferificarea situatiilor de castig.
TEST(BoardTest, CheckWin) {
    Board board;
    board.MakeMove(Point(0, 0), Sign::X);
    board.MakeMove(Point(0, 1), Sign::X);
    board.MakeMove(Point(0, 2), Sign::X);
    
    EXPECT_TRUE(board.CheckWinSituation(Sign::X));  // X trebuie sa fie castigator
    Board board2;
    board2.MakeMove(Point(1, 0), Sign::O);
    board2.MakeMove(Point(1, 1), Sign::O);
    board2.MakeMove(Point(1, 2), Sign::O);
    
    EXPECT_TRUE(board.CheckWinSituation(Sign::O));  // O trebuie sa fie castigator
}

// Test pentru situatia de egalitate
TEST(BoardTest, CheckDraw) {
    Board board;
    board.MakeMove(Point(0, 0), Sign::X);
    board.MakeMove(Point(0, 1), Sign::O);
    board.MakeMove(Point(0, 2), Sign::X);
    board.MakeMove(Point(1, 0), Sign::O);
    board.MakeMove(Point(1, 1), Sign::X);
    board.MakeMove(Point(1, 2), Sign::O);
    board.MakeMove(Point(2, 0), Sign::X);
    board.MakeMove(Point(2, 1), Sign::X);
    board.MakeMove(Point(2, 2), Sign::O);

    EXPECT_TRUE(board.CheckDrawSituation());
}