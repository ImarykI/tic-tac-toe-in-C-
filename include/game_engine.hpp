#pragma once
#include <iostream>
#include "painter.hpp"
#include "robot.hpp"
#include "game_status.hpp"
#include "board.hpp"

class GameEngine{
    public:

        static const std::string gameModeMenu;
        static const std::string chooseSignMenu;
        static const std::string robotDiffMenu;
        static const std::string instructionsMsg;

        //Constructori
        GameEngine();
        GameEngine(Board board, Player player1, Player player2, GameStatus status, Painter painter, short int currPlayerNumber);
        GameEngine(const GameEngine& gameEngine);

        void StartGame();
        bool IsGameOver() const;
        void RunGame();
        
        GameStatus CheckStatus() const;
        Board& GetBoard();

		GameEngine& operator=(const GameEngine& gameEngine);
		bool operator==(const GameEngine& other)const;

    
        friend std::istream& operator >> (std::istream& in, GameEngine& gameEngine);
        friend std::ostream& operator << (std::ostream& out, const GameEngine& gameEngine);

        bool isMultiplayer = false;
    private:
        Board board;
        Player player1;
        Player player2;
        Robot robot;
        GameStatus status;
        Painter painter;

        short int currentPlayerNumber;

        void SwitchPlayer();
        void HandleMove();

};


