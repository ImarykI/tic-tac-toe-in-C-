#pragma once

#include "player.hpp"
#include "difficulty.hpp"
#include "point.hpp"

class Robot : public Player{
    public:
        Robot(Difficulty diff, Sign sign_);
        Difficulty GetDifficulty() const;
        Point MakeMove(Board& board);
    private:
        Difficulty difficulty;
        Point MakeRandomMove(Board& board);
        Point MakeWinningMove(Board& board);       

};
