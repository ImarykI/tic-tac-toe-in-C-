#pragma once

class RobotMove{
    friend class Robot;
    int x;
    int y;
    int score;
public:
    RobotMove(){};
    RobotMove(int Score):score(Score){};
};