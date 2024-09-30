#include "../include/board.hpp"
#include <cstdio>

    Board::Board(){Board::InitBoard();};

    void Board::MakeMove(Point p, Sign sign)
    {
        if(Board::IsMoveValid(p)){
            board_[p.GetX()][p.GetY()] = sign;
        }
    };

    Sign Board::GetPointInBoard(Point point) const{
        return board_[point.GetX()][point.GetY()];
    };


    bool Board::IsMoveValid(Point p) const
    {
        if( board_[p.GetX()][p.GetY()] == Sign::Empty && (p.GetX()<=3 && p.GetY()<=3)) return true;
        else return false;
    };

    bool Board::CheckWinSituation(Sign sign) const{
        //Verificare pe randuri
        for (int i = 0; i < 3; i++) {
            if (board_[i][0] == sign && board_[i][1] == sign && board_[i][2] == sign) {
                return true;
            }
        }
        //Verificarea pe coloane
        for (int f = 0; f < 3; f++) {
            if (board_[0][f] == sign && board_[1][f] == sign && board_[2][f] == sign) {
                return true;
            }
        }
        //Verificarea pe diagonale
        if (board_[0][0] == sign && board_[1][1] == sign && board_[2][2] == sign) {
            return true;
        }
        if (board_[0][2] == sign && board_[1][1] == sign && board_[2][0] == sign) {
            return true;
        }
        return false;
    };

    bool Board::CheckDrawSituation() const{

        //Verifică dacă deja este o situatie de castig pentru unul dinter semne.
        if (CheckWinSituation(Sign::O) || CheckWinSituation(Sign::X)) return false;

        //Verifică dacă mai sunt locuri libere pe masă.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board_[i][j] == Sign::Empty) return false;
            }
        }

        return true;
    };

    void Board::InitBoard(){
        for(int i = 0; i<3; i++){
            for(int f = 0; f<3; f++){
                board_[i][f] = Sign::Empty;
            };
        };
    };
