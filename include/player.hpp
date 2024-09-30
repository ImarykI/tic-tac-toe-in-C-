#pragma once

#include "board.hpp"

class Player{
    public:
        Player(Sign sign);
        Sign GetSign() const;

    protected:
        Sign sign_;
};
