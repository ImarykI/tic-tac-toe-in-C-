#include "../include/robot.hpp"
#include <vector>

Robot::Robot(){};

Robot::Robot(Difficulty diff, Sign sign): Player(sign){
    difficulty = diff;
    sign_= sign;
};

Robot::Robot(const Robot& robot): Player(robot.sign_){
    sign_ = robot.GetSign();
    difficulty = robot.GetDifficulty();
};

Robot& Robot::operator=(const Robot& other){
    sign_ = other.GetSign();
    difficulty = other.GetDifficulty();
    return *this;
};
bool Robot::operator==(const Robot& other)const{
    return sign_ == other.GetSign() && difficulty == other.GetDifficulty();
};




std::istream& operator >> (std::istream& in, Robot& robot){
    
    char imputChar;

    in >> imputChar;

    switch (imputChar)
    {
    case 'x':
        robot = Robot(Difficulty::Experienced,Sign::X);
        break;
    case 'o':
        robot = Robot(Difficulty::Expert,Sign::O);
        break;
    default:
        robot = Robot(Difficulty::Noob, Sign::Empty);
        break;
    }

    return in;
};

std::ostream& operator << (std::ostream& out, const Robot& robot){
        
    switch (robot.GetDifficulty())
    {
    case Difficulty::Noob:
        out << robot.GetSign() <<" Noob";
        break;
    case Difficulty::Experienced:
        out << robot.GetSign() << " Experienced";
        break;
    case Difficulty::Expert:
        out << robot.GetSign() << " Expert";
        break;
    }
    return out;
};



Difficulty Robot::GetDifficulty() const{
    return difficulty;
};

Point Robot::MakeMove(Board& board) {
    switch (difficulty) {
        case Difficulty::Noob:
            return MakeRandomMove(board);
        case Difficulty::Experienced:
        //     return MakeWinningMove(board);
        case Difficulty::Expert:
            RobotMove bestMove = MakeWinningMove(board, sign_);
        return Point(bestMove.x,bestMove.y);
    };
    return Point(2, 2);
};

//------Merge pe prima celulă liberă pe care o găsește în tabel.----
Point Robot::MakeRandomMove(Board& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.GetPointInBoard(Point(i,j)) == Sign::Empty) {
                return Point(i, j);
            }
        }
    }
    return Point(-1, -1); // În caz că nu găsește o celulă -> Nu ar trebui sa se intample
}

RobotMove Robot::MakeWinningMove(Board& board, Sign player) {

    if(board.CheckWinSituation(this->sign_)) return RobotMove(10);
    else if (board.CheckWinSituation(this->sign_ == Sign::O ? Sign::X : Sign::O)) return RobotMove(-10);
    else if (board.CheckDrawSituation()) return RobotMove(0);

    std::vector <RobotMove> moves;

    for(int y = 0; y < 3; y++){
        for(int x = 0; x < 3; x++){
            if (board.GetPointInBoard(Point(x,y)) == Sign::Empty) {
                RobotMove robotMove;
                robotMove.x = x;
                robotMove.y = y;
                board.MakeMove(Point(x, y), player);
                if(player == this->sign_){
                    robotMove.score = MakeWinningMove(board, this->sign_ == Sign::O ? Sign::X : Sign::O).score;
                } else {
                    robotMove.score = MakeWinningMove(board, this->sign_).score;
                }
                moves.push_back(robotMove);
                board.RobotMove(Point(x, y), Sign::Empty);
            }
        };
    };
    int bestMove = 0;
    if (player == this->sign_){
        int bestScore = -100000000;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i].score > bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }else{
        int bestScore = 100000000;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i].score < bestScore){
                bestMove = i;
                bestScore = moves[i].score;
            }
        }
    }

    return moves[bestMove];
};

