#pragma once

#include "../include/abstract_painter.hpp"

class Painter: public AbstractPainter {
	public:

		//Constuctori
		Painter();
		Painter(const Painter& painter);

    	Painter& operator=(const Painter& other);
		bool operator==(const Painter& other)const;

		virtual void ClearFrame();
		virtual void DrawBoard(Sign board[3][3]);
		virtual void PrintGameStatus(Player player, GameStatus currentGameStatus);
};

std::istream& operator >> (std::istream& in, Painter& painter);
std::ostream& operator << (std::ostream& out, const Painter& painter);
