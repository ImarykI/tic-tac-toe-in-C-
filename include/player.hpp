#pragma once

#include "board.hpp"

class Player{
    public:
        //Constructori
        Player();
        Player(Sign sign);
        Player(const Player& player);

        Sign GetSign() const;

    	Player& operator=(const Player& other);
		bool operator==(const Player& other)const;


    protected:
        Sign sign_;
};

std::istream& operator >> (std::istream& in, Player& player);
std::ostream& operator << (std::ostream& out, const Player& player);
