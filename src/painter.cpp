#include "../include/painter.hpp"

const std::string Painter::oWinMsg = "O won the game!\n";
const std::string Painter::xWinMsg = "X won the game!\n";
const std::string Painter::tieMsg = "The game concluded in a tie!\n";
const std::string Painter::defMsg = "-----Ceva nu a mers bine!!!!-----";
const std::string Painter::xRunStatus = "X: made a move, the game is still running\n";
const std::string Painter::oRunStatus = "O: made a move, the game is still running\n";

Painter::Painter()
{
};

Painter::Painter(const Painter &painter)
{
	*this = painter;
};

Painter& Painter::operator=(const Painter& other){
 	*this = other;
 	return *this;
};

bool Painter::operator==(const Painter& other)const{
	return *this == other;
};

std::istream& operator >> (std::istream& in, Painter& painter){
	return in;
};


std::ostream& operator << (std::ostream& out, const Painter& painter){
	return out;
};



void Painter::ClearFrame(){
    system("cls");
};


void Painter::DrawBoard(std::array<std::array<Sign, 3>, 3> board){
	std::cout << "  1   2   3\n";
	for(int i = 0; i < 3; i++)
	{

		printf("%d",i+1);
		for(int j = 0; j < 3; j++)
		{	
			
			switch (board[i][j])
			{
			case Sign::Empty:
				std::cout << "   ";
				break;
			
			case Sign::O:
				std::cout << " O ";
				break;

			case Sign::X:
				std::cout << " X ";
				break;
			}

			if(j < 2) std::cout << "|";
		}
		std::cout << i+1 << std::endl;
		if(i<2) std::cout<<" -----------\n";
	}
	std::cout << "  1   2   3\n";
};

void Painter::PrintGameStatus(Player player, GameStatus currentGameStatus){
	switch (currentGameStatus)
	{
	case GameStatus::Running:
		if(player.GetSign() == Sign::O) std::cout << oRunStatus;
		else if(player.GetSign() == Sign::X) std::cout << xRunStatus;
		break;
	
	case GameStatus::WinnerO:
		std::cout << oWinMsg;
		break;

	case GameStatus::WinnerX:
		std::cout << xWinMsg;
		break;

	case GameStatus::Tie:
		std::cout << tieMsg;
		break;

	default:
		std::cout << defMsg;
		break;
	}
};