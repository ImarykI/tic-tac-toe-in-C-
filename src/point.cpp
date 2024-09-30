#include "../include/point.hpp"
#include <stdio.h>

    Point::Point(int x, int y){
        x_ = x;
        y_ = y;
    };

    int Point::GetX() const{
      return x_;
    };

    int Point::GetY() const{
      return y_;
    };
