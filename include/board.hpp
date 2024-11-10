#pragma once
#include <iostream>
#include <array>
#include "point.hpp"
#include "sign.hpp"

	class Board {
		friend class GameEngine;
	public:
	
		//Constructori
		Board();
		Board(const Board& b);
		Board(std::array<std::array<Sign, 3>, 3> board);

		Board& operator=(const Board& b);
		bool operator==(const Board& other)const;
		void RobotMove(Point p, Sign sign);
		void MakeMove(Point p, Sign sign);
		bool IsMoveValid(Point p) const;
		bool CheckWinSituation(Sign sign) const;
		bool CheckDrawSituation() const;
		Sign GetPointInBoard(Point point) const;

	private:
		std::array<std::array<Sign, 3>, 3> board_;
		void InitBoard();
	};

std::istream& operator >> (std::istream& in, Board& board);
std::ostream& operator << (std::ostream& out, const Board& board);