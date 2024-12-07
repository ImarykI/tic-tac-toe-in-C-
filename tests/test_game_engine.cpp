#include "../gtest/include/gtest.h"
#include "../include/game_engine.hpp" 

//Daca la initializare jocul nu este marcat ca terminat.
TEST(GameEngineTests, DefaultConstructor) {
    GameEngine gameEngine;
    EXPECT_EQ(gameEngine.IsGameOver(), false);
}

//Metoda de schimbare a jucatorului functioneaza
TEST(GameEngineTests, SwitchPlayer) {
    Board board;
    Player player1("X");
    Player player2("O");
    Painter painter;
    GameEngine gameEngine(board, player1, player2, GameStatus::Running, painter, 1);

    gameEngine.SwitchPlayer()

    EXPECT_EQ(gameEngine.currentPlayerNumber == 2, true);
}

//Daca doua motoare sunt egale.
TEST(GameEngineTests, EqualityOperator) {
    GameEngine game1;
    GameEngine game2;

    EXPECT_TRUE(game1 == game2);
}
