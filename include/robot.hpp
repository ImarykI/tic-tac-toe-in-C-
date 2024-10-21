#pragma once

#include "player.hpp"
#include "difficulty.hpp"
#include "point.hpp"

class Robot : public Player{
    public:
        //Constructori
        Robot();
        Robot(Difficulty diff, Sign sign_);
        Robot(const Robot& robot);

    	Robot& operator=(const Robot& other);
		bool operator==(const Robot& other)const;


        Difficulty GetDifficulty() const;
        Point MakeMove(Board& board);
    private:
        Difficulty difficulty;
        Point MakeRandomMove(Board& board);
        Point MakeWinningMove(Board& board);       

};

std::istream& operator >> (std::istream& in, Robot& robot);
std::ostream& operator << (std::ostream& out, const Robot& robot);

