#pragma once
#include <iostream>
#include "../include/abstract_painter.hpp"

class Painter: public AbstractPainter {
	static const std::string oWinMsg;
	static const std::string xWinMsg;
	static const std::string tieMsg;
	static const std::string defMsg;
	static const std::string xRunStatus;
	static const std::string oRunStatus;

	public:

		//Constuctori
		Painter();
		Painter(const Painter& painter);

    	Painter& operator=(const Painter& other);
		bool operator==(const Painter& other)const;

		virtual void ClearFrame();
		virtual void DrawBoard(std::array<std::array<Sign, 3>, 3> board);
		virtual void PrintGameStatus(Player player, GameStatus currentGameStatus);
};

std::istream& operator >> (std::istream& in, Painter& painter);
std::ostream& operator << (std::ostream& out, const Painter& painter);
