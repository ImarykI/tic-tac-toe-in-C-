#include "../include/game_engine.hpp"
#include <cstdio>

GameEngine::GameEngine(): player1(Sign::Empty), player2(Sign::Empty){
currentPlayerNumber = 1;
status = GameStatus::Running;
}

void GameEngine::StartGame()
{ 
    while(true){
        painter.ClearFrame();

        char game_mode_var;
        bool is_imput_valid = false;
        printf("Choose a game mode:\n1.Player vs Player\n2.Player vs Robot\n->");
        scanf(" %c", &game_mode_var);
        if(game_mode_var == '1'){
            painter.ClearFrame();
            printf("Chose the sign for Player 1: X or O\n->");
            scanf(" %c", &game_mode_var);
            if(game_mode_var == 'x'){
                player1 = Player(Sign::X);
                player2 = Player(Sign::O);
                is_imput_valid = true;
            } else if(game_mode_var == 'o'){
                player2 = Player(Sign::X);
                player1 = Player(Sign::O);    
                is_imput_valid = true;       
            };
        } else if (game_mode_var == '2')
        {   
            painter.ClearFrame();
            printf("Chose the sign for Player: X or O\n->");
            scanf(" %c", &game_mode_var);
            if(game_mode_var == 'x') player1 = Player(Sign::X);
            else if(game_mode_var == 'o') player1 = Player(Sign::O);
            else continue;
            painter.ClearFrame();
            printf("Chose a difficutly for the robot:\n1. Noob\n2. Experienced\n3. Expert\n->");
            scanf(" %c", &game_mode_var);
            if(game_mode_var == '1'){
                player2 = Robot(Difficulty::Noob, player1.GetSign() == Sign::O ? Sign::X : Sign::O);
                is_imput_valid = true;
            } else if(game_mode_var == '2'){
                player2 = Robot(Difficulty::Experienced, player1.GetSign() == Sign::O ? Sign::X : Sign::O);
                is_imput_valid = true;
            }else if(game_mode_var == '3'){
                player2 = Robot(Difficulty::Expert, player1.GetSign() == Sign::O ? Sign::X : Sign::O);
                is_imput_valid = true;
            }
        }
        if(is_imput_valid) break;
    }
        painter.ClearFrame();
        painter.DrawBoard(board.board_);
};

void GameEngine::RunGame(){
    while(IsGameOver() == false){
        HandleMove();
        painter.ClearFrame();
        painter.DrawBoard(board.board_);
        status = CheckStatus();
        if(currentPlayerNumber == 1) painter.PrintGameStatus(player1, status);
        if(currentPlayerNumber == 2) painter.PrintGameStatus(player2, status);
        SwitchPlayer();
    }
};

bool GameEngine::IsGameOver() const{
    if(status != GameStatus::Running) return true;
    else return false;
};

GameStatus GameEngine::CheckStatus() const{
    if(currentPlayerNumber == 1){
        if(board.CheckWinSituation(player1.GetSign())){
            return player1.GetSign() == Sign::O ? GameStatus::WinnerO : GameStatus::WinnerX;
        };
    }
    if(currentPlayerNumber == 2){
        if(board.CheckWinSituation(player2.GetSign())){
            return player2.GetSign() == Sign::O ? GameStatus::WinnerO : GameStatus::WinnerX;
        };
    }
    if(board.CheckDrawSituation()) return GameStatus::Tie;

return GameStatus::Running;
};

Board& GameEngine::GetBoard(){
    return board;
};

void GameEngine::SwitchPlayer(){
    if (currentPlayerNumber == 1) currentPlayerNumber = 2;
    else currentPlayerNumber = 1;
    
};

void GameEngine::HandleMove(){

    int currentMoveX = 0;
    int currentMoveY = 0;
    if(currentPlayerNumber == 1){
        printf("Player 1 has to chose a move:\nWrite the coordonates of the grid, where you want your sign to be placed\n\
        top left cell is (1 1), bottom right one is (3 3):\n->");
        scanf("%d %d",&currentMoveX, &currentMoveY);
        board.MakeMove(Point(currentMoveX-1,currentMoveY-1), player1.GetSign());
    }
    if(currentPlayerNumber == 2){
        printf("Player 2 has to chose a move:\nWrite the coordonates of the grid, where you want your sign to be placed\n\
        top left cell is (1 1), bottom right one is (3 3):\n->");
        scanf("%d %d",&currentMoveX, &currentMoveY);
        board.MakeMove(Point(currentMoveX-1,currentMoveY-1), player2.GetSign());
    }
};