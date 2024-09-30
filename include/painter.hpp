#pragma once

#include "board.hpp"
#include "player.hpp"
#include "game_status.hpp"

class Painter {
	public:
		void ClearFrame();
		void DrawBoard(Sign board[3][3]);
		void PrintGameStatus(Player player, GameStatus currentGameStatus);
};
