#include "../include/painter.hpp"
#include <cstdio>
#include <stdlib.h>

void Painter::ClearFrame(){
	system("cls");
};

void Painter::DrawBoard(Sign board[3][3]){
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{	
			switch (board[i][j])
			{
			case Sign::Empty:
				printf("   ");
				break;
			
			case Sign::O:
				printf(" O ");
				break;

			case Sign::X:
				printf(" X ");
				break;
			}

			if(j < 2) printf("|");
		}
		printf("\n");
		if(i<2) printf("-----------\n");
	}
	printf("\n");
};

void Painter::PrintGameStatus(Player player, GameStatus currentGameStatus){
	switch (currentGameStatus)
	{
	case GameStatus::Running:
		if(player.GetSign() == Sign::O) printf("O: made a move, the game is still running\n");
		else if(player.GetSign() == Sign::X)printf("X: made a move, the game is still running\n");
		break;
	
	case GameStatus::WinnerO:
		printf("O won the game!\n");
		break;

	case GameStatus::WinnerX:
		printf("X won the game!\n");
		break;

	case GameStatus::Tie:
		printf("The game concluded in a tie!\n");
		break;

	default:
		printf("-----Ceva nu a mers bine!!!!-----");
		break;
	}
};