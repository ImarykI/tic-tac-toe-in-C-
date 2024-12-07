#pragma once
#include <iostream>
#include "../include/abstract_painter.hpp"

/**
 * @brief Clasa ce se ocupă de afișarea în consolă a jocului.
 * 
 */
class Painter: public AbstractPainter {
	static const std::string oWinMsg;
	static const std::string xWinMsg;
	static const std::string tieMsg;
	static const std::string defMsg;
	static const std::string xRunStatus;
	static const std::string oRunStatus;

	public:

		/**
		 * @brief Construiește un nou obiect Painter
		 * 
		 */
		Painter();

		/**
		 * @brief Copie o instantă într-un nou obiect Painter
		 * 
		 * @param painter Referință la painter-ul ce trebuie copiat.
		 */
		Painter(const Painter& painter);

		/**
		 * @brief Atribuirea unui painter la altul.
		 * 
		 * @param other Referință către cealaltă instanță de tip Painter
		 * @return Painter& : Referința din paramentru.
		 */
    	Painter& operator=(const Painter& other);

		/**
		 * @brief Compararea a doi Painteri.
		 * 
		 * @param other Referință către cealaltă instanță de tip Painter
		 * @return true : Dacă Painterii sunt aceiași.
		 * @return false : Dacă Painterii sunt diferiți.
		 */
		bool operator==(const Painter& other)const;

		/**
		 * @brief Metodă ce curăță consola
		 * 
		 */
		virtual void ClearFrame();

		/**
		 * @brief Metodă ce desenează masa în starea ei curentă.
		 * 
		 * @param board Array bidimensional 3/3
		 */
		virtual void DrawBoard(std::array<std::array<Sign, BOARD_SIZE>, BOARD_SIZE> board);

		/**
		 * @brief Metodă ce afișează situația curentă a jocului.
		 * 
		 * @param player Jucătorul pentru care se printează statutul.
		 * @param currentGameStatus Statutul curent al jocului.
		 */
		virtual void PrintGameStatus(Player player, GameStatus currentGameStatus);
};

/**
 * @brief Citirea de la consolă pentru Painter.
 * 
 * @param in Referință istream.
 * @param painter Referință painter.
 * @return std::istream& citește valorile de la consolă.
 */
std::istream& operator >> (std::istream& in, Painter& painter);

/**
 * @brief Afișarea la consolă a clasei Painter.
 * 
 * @param out Referință ostream.
 * @param painter REferință painter.
 * @return std::ostream& afișează valorile la consolă.
 */
std::ostream& operator << (std::ostream& out, const Painter& painter);
