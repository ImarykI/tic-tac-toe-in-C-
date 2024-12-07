#pragma once

#include "player.hpp"
#include "difficulty.hpp"
#include "point.hpp"
#include "robot_move.hpp"

/**
 * @brief Clasa ce reprezință robotul sau AI. Moștenește de la clasa Player
 * 
 */
class Robot : public Player{

    public:
        /**
         * @brief construiește un nou obiect de tip Robot
         * 
         */
        Robot();

        /**
         * @brief Construiește un nou obiect de tip Robot cu parametri.
         * 
         * @param diff Dificultatea dorită pentru AI.
         * @param sign_ Semnul cu care va juca robotul. X sau O.
         */
        Robot(Difficulty diff, Sign sign_);

        /**
         * @brief Copie dificultatea și semnul din referința robot.
         * 
         * @param robot Referința de tip Robot.
         */
        Robot(const Robot& robot);

        /**
         * @brief Copie dificultatea și semnul din referința robot.
         * 
         * @param other  Referința robot.
         * @return Robot& Referința la noul obiect creat.
         */
    	Robot& operator=(const Robot& other);

        /**
         * @brief Compară semnul și dificulatea cu referința robot.
         * 
         * @param other Referința robot.
         * @return true Dacă semnul și dificultatea sunt egale.
         * @return false Dacă cel puțin una dintre ele nu coincide.
         */
		bool operator==(const Robot& other)const;

        /**
         * @brief Obține dificultatea robotului.
         * 
         * @return Difficulty : Dificultatea robotului.
         */
        Difficulty GetDifficulty() const;

        /**
         * @brief Robotul face o mișcare pe masă.
         * 
         * @param board Referință la masă.
         * @return Point : Punctul unde dorește să fie mișcarea.
         */
        Point MakeMove(Board& board);
    private:
     

        short int currentPlayer=1;

        Difficulty difficulty;

        /**
         * @brief Robotul face o mișcare simplă, ușor de prezis, parcurge matricea de sus în jos, de la dreapta la stanga.
         * 
         * @param board Referință la masă.
         * @return Point : Punctul unde a desis să facă mișcarea.
         */
        Point MakeRandomMove(Board& board);

        /**
         * @brief Robotul face o mișcare calculată, câștigătoare.
         * 
         * @param board Referință la masă.
         * @param player Semnul jucătorului.
         * @return RobotMove : O mișcare de robot.
         */
        RobotMove MakeWinningMove(Board& board, Sign player);

};

/**
 * @brief Schimbă semnul unei instante de tip Robot.
 * 
 * @param in input
 * @param robot referința la robot.
 * @return std::istream& 
 */
std::istream& operator >> (std::istream& in, Robot& robot);

/**
 * @brief Afișează la consolă dificulatea robotului.
 * 
 * @param out output
 * @param robot Referința la robot.
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& out, const Robot& robot);

