#pragma once

#include "player.hpp"
#include "difficulty.hpp"

class Robot : public Player{
    public:
        Robot(Difficulty diff);
        Difficulty getDifficulty() const;
    private:
        Difficulty difficulty;
        Point makeMove(Board board);

};
