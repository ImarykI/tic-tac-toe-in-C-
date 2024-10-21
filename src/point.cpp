#include "../include/point.hpp"
#include <stdio.h>

Point::Point(){};

Point::Point(int x, int y){
    x_ = x;
    y_ = y;
};

Point::Point(const Point& point){
  x_ = point.GetX();
  y_ = point.GetY();
};

Point Point::operator=(const Point &other)
{
    x_ = other.GetX();
    y_ = other.GetY();

    return *this;
}
bool Point::operator==(const Point &other) const
{
    return x_==other.GetX() && y_ == other.GetY();
}

int Point::GetX() const
{
    return x_;
};

int Point::GetY() const{
  return y_;
};

std::istream &operator>>(std::istream &in, Point &point){
    int x, y;
    in >> x >> y;
    point = Point(x, y);
    return in;
};

std::ostream &operator<<(std::ostream &out, const Point &point){
    out << point.GetX() << " " << point.GetY();
    return out;
};