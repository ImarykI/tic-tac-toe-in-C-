#pragma once
#include <iostream>
#include "point.hpp"
#include "sign.hpp"

	class Board {
		friend class GameEngine;
	public:
	
		//Constructori
		Board();
		Board(const Board& b);
		Board(Sign board[3][3]);

		Board& operator=(const Board& b);
		bool operator==(const Board& other)const;

		void MakeMove(Point p, Sign sign);
		bool IsMoveValid(Point p) const;
		bool CheckWinSituation(Sign sign) const;
		bool CheckDrawSituation() const;
		Sign GetPointInBoard(Point point) const;

	private:
		Sign board_[3][3];
		void InitBoard();
	};

std::istream& operator >> (std::istream& in, Board& board);
std::ostream& operator << (std::ostream& out, const Board& board);