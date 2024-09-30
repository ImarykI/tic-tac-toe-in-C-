#include "../include/player.hpp"

        Player::Player(Sign sign){
            sign_ = sign;
        };

        Sign Player::GetSign() const{
            return sign_;
        };
