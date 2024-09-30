#include "../include/robot.hpp"

Robot::Robot(Difficulty diff, Sign sign): Player(sign){
    difficulty = diff;
    sign_=sign;
};

Difficulty Robot::GetDifficulty() const{
    return difficulty;
};

Point Robot::MakeMove(Board& board) {
    switch (difficulty) {
        case Difficulty::Noob:
            return MakeRandomMove(board);
        case Difficulty::Experienced:
            return MakeWinningMove(board);
        case Difficulty::Expert:
            if (Point winMove = MakeWinningMove(board); winMove.GetX() != -1) {
                return winMove;
            }
            return MakeRandomMove(board);
    };
    return Point(-1, -1);
}

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

//-------Inainte de a confirma celula pe care merge, verifica daca acea celula
//-------aduce un gastig
Point Robot::MakeWinningMove(Board& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.GetPointInBoard(Point(i,j)) == Sign::Empty) {
                board.MakeMove(Point(i, j), sign_);
                if (board.CheckWinSituation(sign_)) {
                    board.MakeMove(Point(i, j),Sign::Empty);
                    return Point(i, j);
                }
                board.MakeMove(Point(i, j), Sign::Empty); // Undo the move
            }
        }
    }
    return Point(-1, -1); //In caz ca nu vede o celula castigatoare
}

