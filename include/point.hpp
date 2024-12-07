#pragma once
#include <iostream>

    /**
     * @brief Clasa ce reprezintă un punct cu coordanatele X și Y.
     * 
     */
    class Point{
    public:

        /**
         * @brief Construiește un nou obiect tip Point
         * 
         */
        Point();

        /**
         * @brief construiește un nou obiect tip Point cu coordonatele X Y
         * 
         * @param x Coordonata X
         * @param y Coordonata Y
         */
        Point(int x, int y);

        /**
         * @brief Copie coordonatele unei instanțe punct.
         * 
         * @param point Referință la puncul din care se copie.
         */
        Point(const Point& point);

        /**
         * @brief Inițializează punctul cu coordonatele din referință.
         * 
         * @param other Referința de tip Point
         * @return Point : Referință de tip Point.
         */
        Point operator=(const Point& other);

        /**
         * @brief Compară cu o instanță tip Point
         * 
         * @param other referința la instanță.
         * @return true Dacă coordonatele coincid.
         * @return false Dacă coordonatele nu coincid.
         */
        bool operator==(const Point& other) const;

        /**
         * @brief Obține coordonata X a punctului.
         * 
         * @return int : poziția X
         */
        int GetX() const;

        /**
         * @brief Obține coordonata Y a punctului.
         * 
         * @return int : poziția Y.
         */
        int GetY() const;
    private:
        int x_;
        int y_;
    };

/**
 * @brief Introdu valorile coordonatelor din consolă
 * 
 * @param in inputul
 * @param point referința la punctul care se va modifica.
 * @return std::istream& 
 */
std::istream& operator >> (std::istream& in, Point& point);

/**
 * @brief Afișează la consolă coordonatele punctului.
 * 
 * @param out outputul
 * @param point referință la obiectul de tip Point.
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& out, const Point& point);