#pragma once

#include "point.hpp"
#include "sign.hpp"

class Board {
	
	public:
		Board();
		void MakeMove(Point p, Sign sign);
		bool isMoveValid(Point p) const;
		bool checkWinSituation(Sign sign) const;
		bool checkDrawSituation() const;

	private:
		Sign board[3][3];
		void InitBoard();
};