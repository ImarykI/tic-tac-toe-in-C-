#pragma once

#include "painter.hpp"
#include "robot.hpp"
#include "game_status.hpp"

class GameEngine{
    public:
        void StartGame();
        bool isGameOver() const;
        
        GameStatus checkStatus() const;
        Board& getBoard();

    private:
        Board board;
        Player player1;
        Player player2;
        Robot robot;
        GameStatus status;

        short int currentPlayerNumber;

        void SwitchPlayer();
        void handleMove();

};