#include "../include/player.hpp"

Player::Player(){};

Player::Player(const Player& player){
    sign_ = player.GetSign();
};

Player::Player(Sign sign){
    sign_ = sign;
};

Sign Player::GetSign() const{
    return sign_;
};


Player& Player::operator=(const Player& other){
    sign_ = other.GetSign();
    return *this;
};
bool Player::operator==(const Player& other)const{
    return sign_ == other.GetSign();
};

std::istream& operator >> (std::istream& in, Player& player){
    char imputChar;

    in >> imputChar;

    switch (imputChar)
    {
    case 'x':
        player = Player(Sign::X);
        break;
    case 'o':
        player = Player(Sign::O);
        break;
    default:
        player = Player(Sign::Empty);
        break;
    }

    return in;

};
std::ostream& operator << (std::ostream& out, const Player& player){
    out << player.GetSign();
    return out;
};

