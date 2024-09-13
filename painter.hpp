#pragma once

#include "board.hpp"

class Painter {
	public:
		void ClearFrame();
		void DrawBoard(Board board);
		void PrintGameStatus();
};