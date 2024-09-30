#pragma once
#include "painter.hpp"
#include "robot.hpp"
#include "game_status.hpp"
#include "board.hpp"

class GameEngine{
    public:
        GameEngine();
        void StartGame();
        bool IsGameOver() const;
        void RunGame();
        
        GameStatus CheckStatus() const;
        Board& GetBoard();

    private:
        Board board;
        Player player1;
        Player player2;
        GameStatus status;
        Painter painter;

        short int currentPlayerNumber;

        void SwitchPlayer();
        void HandleMove();

};
