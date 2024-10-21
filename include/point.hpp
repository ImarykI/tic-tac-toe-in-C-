#pragma once
#include <iostream>

    class Point{
    public:

        //Constructori
        Point();
        Point(int x, int y);
        Point(const Point& point);

        Point operator=(const Point& other);
        bool operator==(const Point& other) const;

        int GetX() const;
        int GetY() const;
    private:
        int x_;
        int y_;
    };

std::istream& operator >> (std::istream& in, Point& point);

std::ostream& operator << (std::ostream& out, const Point& point);