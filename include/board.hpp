#pragma once

#include "point.hpp"
#include "sign.hpp"

	class Board {
		friend class GameEngine;
	public:
		Board();
		void MakeMove(Point p, Sign sign);
		bool IsMoveValid(Point p) const;
		bool CheckWinSituation(Sign sign) const;
		bool CheckDrawSituation() const;
		Sign GetPointInBoard(Point point) const;
	private:
		Sign board_[3][3];
		void InitBoard();
	};