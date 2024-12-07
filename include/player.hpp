#pragma once

#include "board.hpp"

class Player{
    public:
        
        /**
         * @brief Consturiește un obiect de tip Player
         * 
         */
        Player();

        /**
         * @brief Construiește un obiect de tip Player cu paramentrul semn.
         * 
         * @param sign semnul dorit pentru acest jucător. X sau O. Posibil și Empty.
         */
        Player(Sign sign);

        /**
         * @brief Copie un jucător din referință.
         * 
         * @param player Referința la jucător.
         */
        Player(const Player& player);

        /**
         * @brief Obține semnul jucătorului.
         * 
         * @return Sign : Semnul pe care jucătorul îl deține. X sau O. Posibil și Empty.
         */
        Sign GetSign() const;

        /**
         * @brief Copie semnul din referință în obiectl de tip Player.
         * 
         * @param other referința
         * @return Player& : Referința la noul obiect cu semn de tip Player.
         */
    	Player& operator=(const Player& other);
        
        /**
         * @brief Compară semnele a doi jucători.
         * 
         * @param other Referința jucătorului cu care se compară.
         * @return true Dacă semnele sunt aceleași.
         * @return false Dacă semnele sunt diferite.
         */
		bool operator==(const Player& other)const;


    protected:
        Sign sign_;
};

/**
 * @brief Schimbă semnul în dependență de imput.
 * 
 * @param in imputul
 * @param player referința la jucătorul ai cărui semn trebuie schimbat.
 * @return std::istream& 
 */
std::istream& operator >> (std::istream& in, Player& player);

/**
 * @brief Afișează semnul jucătorului.
 * 
 * @param out outputul
 * @param player referința la jucător.
 * @return std::ostream&
 */
std::ostream& operator << (std::ostream& out, const Player& player);
