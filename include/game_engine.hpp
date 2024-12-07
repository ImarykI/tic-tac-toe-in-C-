#pragma once
#include <iostream>
#include "painter.hpp"
#include "robot.hpp"
#include "game_status.hpp"
#include "board.hpp"
#include <sqlite3.h>

/**
 * @brief Motorul de joc ce răspunde de inițializarea și rularea jocului.
 * 
 */
class GameEngine{
    public:

        static const std::string gameModeMenu;
        static const std::string chooseSignMenu;
        static const std::string robotDiffMenu;
        static const std::string instructionsMsg;

        /**
         * @brief Construiește un nou obiect GameEngine.
         * 
         */
        GameEngine();

        /**
         * @brief Inițializează un nou obiect GameEngine cu parametri.
         * 
         * @param board masa pentru joc tip Board
         * @param player1 primul jucător tip Player
         * @param player2 al doilea jucătro tip Player
         * @param status statutul curent al jocului tip GameStatus
         * @param painter painterul tip Painter.
         * @param currPlayerNumber Numărul curent al jucătorului care trebuie să meargă. 1 = Primul jucător, 2 = Al doilea jucător.
         */
        GameEngine(Board board, Player player1, Player player2, GameStatus status, Painter painter, short int currPlayerNumber);

        /**
         * @brief Copie elementele dintr-o instantă GameEngine în alta
         * 
         * @param gameEngine Referință la instanță.
         */
        GameEngine(const GameEngine& gameEngine);

        /**
         * @brief Începe jocul și inițializează toate valorile necesare.
         * 
         */
        void StartGame();

        /**
         * @brief Verifică dacă jocul s-a terminat.
         * 
         * @return true Dacă valoarea GameStatus este diferită de Running.
         * @return false Dacă valoarea GameStatus este Running.
         */
        bool IsGameOver() const;

        /**
         * @brief Rulează jocul într-un ciclu infinit.
         * 
         */
        void RunGame();
        
        /**
         * @brief Verifică statutul jocului și schimbă valoarea gameStatus
         * 
         * @return GameStatus 
         */
        GameStatus CheckStatus() const;

        /**
         * @brief Obține obiectul de tip Board
         * 
         * @return Board& referință la obiect.
         */
        Board& GetBoard();

        /**
         * @brief Copie valorile dintr-o instanță GameEngine.
         * 
         * @param gameEngine instanța.
         * @return GameEngine& Referință la noul obiect creat.
         */
		GameEngine& operator=(const GameEngine& gameEngine);

        /**
         * @brief Compară statutul jocului între două motoare de joc.
         * 
         * @param other obiectul de tip GameEngine cu care se compară statutul.
         * @return true Dacă statutul ambelor obiecte este același.
         * @return false Dacă statutul lor este diferit.
         */
		bool operator==(const GameEngine& other)const;

        /**
         * @brief Inițializare GameEngine de la consolă
         * 
         * @param in istream
         * @param gameEngine referință la motorul de joc
         * @return std::istream& în cascada istream
         */
        friend std::istream& operator >> (std::istream& in, GameEngine& gameEngine);

        /**
         * @brief Afișează la consolă masa de joc și al cui este rândul.
         * 
         * @param out ostream.
         * @param gameEngine referință la motorul de joc
         * @return std::ostream& afișarea în cascada ostream.
         */
        friend std::ostream& operator << (std::ostream& out, const GameEngine& gameEngine);

        /**
         * @brief Inițializează bază de date de tip sqlite3.
         * 
         * @param db Conexiune la baza de date.
         */
        void InitializeDatabase(sqlite3** db);

        /**
         * @brief Actualizează valorile din baza de date.
         * 
         * @param db Referință la baza de date.
         * @param player Referință la șirul de caractere ce reprezintă jucătorul.
         */
        void UpdateWins(sqlite3* db, const std::string& player);

        /**
         * @brief Afișarea valorilor din baza de date la consolă.
         * 
         * @param db Referință la baza de date.
         */
        void DisplayStats(sqlite3* db);

        /**
         * @brief Pornește actualizarea bazei de date în dependență de statutul jocului.
         * 
         * @param status Statutul care determină ce valori se vor actualiza în baza de date.
         */
        void EndGame(GameStatus status);



        bool isMultiplayer = false;
    private:
        Board board;
        Player player1;
        Player player2;
        Robot robot;
        GameStatus status;
        Painter painter;

        short int currentPlayerNumber;

        /**
         * @brief Schimbă rândul jucătorilor și a variabilei currentPlayerNumber între 1 și 2.
         * 
         */
        void SwitchPlayer();

        /**
         * @brief Administrează mișcările în baza inputului utilizatorului.
         * 
         */
        void HandleMove();

};


