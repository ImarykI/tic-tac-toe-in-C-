#pragma once
#include <iostream>
#include <array>
#include "point.hpp"
#include "sign.hpp"


	/**
	 * @brief Masa de joc.
	 * Are clasă prieten pe GameEngine.
	 * 
	 */
	class Board {
		
		const static int BOARD_SIZE = 3;

		friend class GameEngine;
	public:
	
		/**
		 * @brief Construiește un nou obiect Board
		 * 
		 */
		Board();

		/**
		 * @brief Copie instantă într-un nou obiect Board
		 * 
		 * @param b Referință la instantă.
		 */
		Board(const Board& b);

		/**
		 * @brief Copie valorile dintrun array bidimesional 3/3 în board_.
		 * 
		 * @param board Array bidimensional 3 / 3.
		 */
		Board(std::array<std::array<Sign, BOARD_SIZE>, BOARD_SIZE> board);

		/**
		 * @brief Atribuie valorile din array din b în board.
		 * 
		 * @param b Instanță Board de la care se copie valorile
		 * @return Board& : Referința la noul board creat cu valorile din b.
		 */
		Board& operator=(const Board& b);

		/**
		 * @brief Compară cu o instatnță Board.
		 * 
		 * @param other Altă instanță board.
		 * @return true : Dacă toate valorile din board coincid.
		 * @return false : Dacă cel puțin o valoare nu coincide.
		 */
		bool operator==(const Board& other)const;

		/**
		 * @brief Mișcarea Robotului / AI
		 * 
		 * @param p Punctul în care robotul dorește să plaseze semnul
		 * @param sign Semnul ce trebuie plasat pe acel punct
		 */
		void RobotMove(Point p, Sign sign);

		/**
		 * @brief Mișcare pe masă.
		 * 
		 * @param p Punctul unde trebuie făcută mișcarea.
		 * @param sign Semnul cu care trebuie de făcut mișcarea.
		 */
		void MakeMove(Point p, Sign sign);

		/**
		 * @brief Validează mișcarea.
		 * 
		 * @param p Poziția unde se încearcă mișcarea.
		 * @return true : Dacă mișcarea poate fi făcută.
		 * @return false : Dacă mișcarea nu poate fi făcută pe poziția indicată.
		 */
		bool IsMoveValid(Point p) const;

		/**
		 * @brief Verifică dacă este o situație de câștig pe masă.
		 * 
		 * @param sign Semnul pentru care se face verificarea.
		 * @return true Dacă există situație de câștig.
		 * @return false Dacă nu este situație de câștig.
		 */
		bool CheckWinSituation(Sign sign) const;

		/**
		 * @brief Verifică dacă este o situație de egalitate.
		 * 
		 * @return true Dacă este situație de egalitate.
		 * @return false Dacă nu este situație de egalitate.
		 */
		bool CheckDrawSituation() const;

		/**
		 * @brief Opține semnul ce se află pe o poziție pe masă.
		 * 
		 * @param point Poziția pe care se află semnul.
		 * @return Sign : Semnul de pe poziție.
		 */
		Sign GetPointInBoard(Point point) const;

	private:
		std::array<std::array<Sign, BOARD_SIZE>, BOARD_SIZE> board_;

		/**
		 * @brief Inițializează masa cu semne goale.
		 * 
		 */
		void InitBoard();
	};

/**
 * @brief Citește de la tastatură fiecare semn pentru a le adăuga în array.
 * 
 * @param in 
 * @param board Referința la masă.
 * @return std::istream& 
 */
std::istream& operator >> (std::istream& in, Board& board);

/**
 * @brief Afișează valorile de pe masă.
 * 
 * @param out 
 * @param board Referință la masă.
 * @return std::ostream& 
 */
std::ostream& operator << (std::ostream& out, const Board& board);